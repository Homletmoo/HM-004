#include "Base.h"
#include "Chunk.h"

#include "Mesh.h"
#include "Terrain.h"


Chunk::Chunk( glm::ivec3 position, int size, Terrain* terrain ) :
	terrain( terrain ),
	changed( true ),
	position( position ),
	positionAbs( position * size ),
	size( size ),
	id( (int)( glfwGetTime() * 100000 ) )
{
	blocks = new Block**[size];
	for ( int i = 0; i < size; i++ )
	{
		blocks[i] = new Block*[size];
		for ( int j = 0; j < size; j++ )
		{
			blocks[i][j] = new Block[size];
			for ( int k = 0; k < size; k++ )
			{
				int x = i + position.x * size;
				int y = j + position.y * size;
				int z = k + position.z * size;

				float slope = 48 - sqrtf( powf( 1 - x / 144.0f, 4 ) + powf( 1 - z / 144.0f, 4 ) ) * 80;
				if ( y < slope + ( glm::simplex( glm::vec2( x / 100.0, z / 100.0 ) ) + 1 ) * 16 )
				{
					blocks[i][j][k].id = 3;
				} else
				{
					blocks[i][j][k].id = 0;
				}
			}
		}
	}
}


/*!
 * Returns the block type at this position in the chunk.
 */
Block& Chunk::getBlockAt( glm::ivec3 pos )
{
	return blocks[pos.x][pos.y][pos.z];
}


Block& Chunk::getBlockAt( int x, int y, int z )
{
	return blocks[x][y][z];
}


/*!
 * Returns the unique integer ID for this chunk.
 */
int Chunk::getID( void )
{
	return id;
}


/*!
 * Returns a pointer to the mesh for this chunk.
 */
Mesh* Chunk::getMesh()
{
	if ( changed )
	{
		changed = false;
		mesh = generateMesh();
	}

	return mesh;
}


/*!
 * Generates a mesh for the chunk using a greedy alogrithm.
 */
Mesh* Chunk::generateMesh()
{
	std::vector<vertex> vertices;
	std::vector<GLuint> indices;
	
	for ( int d = 0; d < 3; d++ )
	{
		glm::ivec3 p, q;
		int u = ( d == 0 ) ? 2 : 0;
		int v = ( d == 1 ) ? 2 : 1;
		char** type = new char*[size];
		bool** face = new bool*[size];
		for ( int m = 0; m < size; m++ )
		{
			type[m] = new char[size];
			face[m] = new bool[size];
		}

		q[d] = 1;

		// Perform algorithm on set of 2D slices along axis d.
		for ( p[d] = 0; p[d] <= size; p[d]++ )
		{
			// Compute mask for slice.
			for ( p[u] = 0; p[u] < size; p[u]++ )
			for ( p[v] = 0; p[v] < size; p[v]++ )
			{
				char near = (
					p[d] == 0 ?
					terrain->getBlockAt( p - q + positionAbs ).id :
					blocks[p[0]-q[0]][p[1]-q[1]][p[2]-q[2]].id
				);
				char far = (
					p[d] == size ?
					terrain->getBlockAt( p + positionAbs ).id :
					blocks[p[0]][p[1]][p[2]].id
				);
				type[p[u]][p[v]] = ( near != 0 ) ^ ( far != 0 ) ? near | far : 0;
				face[p[u]][p[v]] = ( near != 0 );
			}

			// Generate mesh for slice lexicographically.
			for ( int j = 0; j < size; j++ )
			for ( int i = 0; i < size; )
			{
				char t = type[i][j];
				if ( t > 0 )
				{
					// Whether the quad faces backwards along the axis.
					bool f = face[i][j];

					// Compute width and height of quad.
					int w, h = size;
					for ( w = 0; i + w < size && type[i+w][j] == t && face[i+w][j] == f; w++ )
					{
						int th;
						for ( th = 1; j + th < size && type[i+w][j+th] == t && face[i+w][j+th] == f; th++ );
						if ( h > th )
							h = th;
					}

					// Flip faces on x and y axes because reasons.
					if ( d != 2 )
						f = !f;

					// Add quad.
					p[u] = f ? i : i + w;
					p[v] = j;
					glm::vec3 wd; wd[u] = (float) ( f ? w : -w );
					glm::vec3 hd; hd[v] = (float) ( h );
					int texture = terrain->getBlockTypeFromId(t).textures[d + (int) f];
					std::cout << texture << std::endl;
					Mesh::appendQuad(
						quad(
							glm::vec3( positionAbs ) + glm::vec3( p ),
							glm::vec3( positionAbs ) + glm::vec3( p[0]+wd[0]      , p[1]+wd[1]      , p[2]+wd[2]       ),
							glm::vec3( positionAbs ) + glm::vec3( p[0]+wd[0]+hd[0], p[1]+wd[1]+hd[1], p[2]+wd[2]+hd[2] ),
							glm::vec3( positionAbs ) + glm::vec3( p[0]      +hd[0], p[1]      +hd[1], p[2]      +hd[2] ),
							glm::vec3( f ? q : -q ),
							(float) w, (float) h, texture
						),
						&vertices,
						&indices
					);

					// Mark this area clear on mask.
					for ( int l = i; l < i + w; l++ )
					for ( int k = j; k < j + h; k++ )
						type[l][k] = 0;

					// Advance along by width of quad.
					i += w;
				} else
					// Advance along by one.
					i++;
			}
		}

		// Deallocate mask.
		for ( int m = 0; m < size; m++ )
		{
			delete[] type[m];
			delete[] face[m];
		}
		delete[] type;
		delete[] face;
	}

	return new Mesh( vertices, indices, GL_TRIANGLE_FAN );
}
