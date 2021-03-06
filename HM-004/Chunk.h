#pragma once


struct BlockType;

class Mesh;
class Terrain;


struct Block {
	char id;
};


class Chunk {
private:
	Block*** blocks;

	Terrain* terrain;

	Mesh* mesh;
	Mesh* generateMesh();
	bool changed;

	glm::ivec3 position;
	glm::ivec3 positionAbs;
	int size;
	int id;

public:
	Chunk( glm::ivec3 position, int size, Terrain* terrain );
	
	Block& getBlockAt( glm::ivec3 pos );
	Block& getBlockAt( int x, int y, int z );

	int   getID( void );
	Mesh* getMesh();
};
