#pragma once


class VAO;


struct vertex {
	GLfloat x,  y,  z,
			s,  t , p,
		   nx, ny, nz;
};


struct cube {
	bool front, back,
		 right, left,
		 top, bottom;
};


struct quad {
	quad(
		glm::vec3 p0,
		glm::vec3 p1,
		glm::vec3 p2,
		glm::vec3 p3,
		glm::vec3 n,
		float w,
		float h,
		int t
	) :
		p0( p0 ),
		p1( p1 ),
		p2( p2 ),
		p3( p3 ),
		n( n ),
		w( w ),
		h( h ),
		t( t )
	{};

	glm::vec3 p0, p1, p2, p3, n;
	float w, h;
	int t;
};


class Mesh {
private:
	GLuint vertexID;
	GLuint indexID;
	GLenum poly_mode;
	int count;
	bool empty;

	VAO* vao;

	std::vector<vertex>   vertices;
	std::vector<GLuint> indices;
	
protected:
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec4 orientation;

public:
	Mesh(
		std::vector<vertex> vertices,
		std::vector<GLuint> indices,
		GLenum poly_mode
	);

	void rebuffer(
		std::vector<vertex> vertices,
		std::vector<GLuint> indices,
		GLenum poly_mode
	);

	       void   bind( void );
	static void unbind( void );

	void draw( void );

	virtual void    setPosition( glm::vec3 position );
	virtual void       setScale( glm::vec3 scale );
	virtual void setOrientation( glm::vec4 orientation );

	glm::vec3 getPosition( void );
	glm::vec3 getScale( void );
	glm::vec4 getOrientation( void );

	virtual void translate( glm::vec3 offset );
	virtual void addScale( glm::vec3 factor );
	virtual void rotate( float amount );

	static Mesh* createCube(
		glm::vec3 position,
		glm::vec3 size
	);

	static void appendCube(
		glm::vec3 position,
		float size,
		std::vector<vertex>* v,
		std::vector<GLuint>* i
	);

	static void appendCube(
		glm::vec3 position,
		float size,
		cube faces,
		std::vector<vertex>* v,
		std::vector<GLuint>* i
	);

	static void appendQuad(
		quad quad,
		std::vector<vertex>* v,
		std::vector<GLuint>* i
	);

	static Mesh* createTorus(
		glm::vec3 position,
		glm::vec3 size,
		float radius,
		float tube_radius,
		int resolution
	);
};


class LerpMesh : public Mesh {
private:
	glm::vec3 positionOld;
	glm::vec3 scaleOld;
	glm::vec4 orientationOld;

public:
	LerpMesh(
		std::vector<vertex> vertices,
		std::vector<GLuint> indices,
		GLenum poly_mode
	);

	void    setPosition( glm::vec3 position );
	void       setScale( glm::vec3 scale );
	void setOrientation( glm::vec4 orientation );

	glm::vec3 getOldPosition( void );
	glm::vec3 getOldScale( void );
	glm::vec4 getOldOrientation( void );

	void translate( glm::vec3 offset );
	void addScale( glm::vec3 factor );
	void rotate( float amount );
};
