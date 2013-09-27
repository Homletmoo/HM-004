#include "Base.h"
#include "Matrices.h"


Matrices::Matrices() :
	     model( 1.0 ),
	      view( 1.0 ),
	projection( 1.0 ),
	 modelView( 1.0 )
{
}


void Matrices::loadIdentity( void )
{
	model = glm::mat4( 1.0 );
}


void Matrices::translate( glm::vec3 translation )
{
	model *= glm::translate( translation );
}


void Matrices::scale( glm::vec3 factor )
{
	model *= glm::scale( factor );
}


void Matrices::rotate( glm::vec3 axis, float angle )
{
	model *= glm::rotate( angle, axis );
}


void Matrices::lookAt( glm::vec3 position, glm::vec3 target, glm::vec3 up )
{
	view = glm::lookAt( position, target, up );
}


void Matrices::setProjection( double fov, double ratio, double near, double far )
{
	projection = glm::perspective( fov, ratio, near, far );
}


void Matrices::computeModelView( void )
{
	modelView = view * model;
}


glm::mat4 Matrices::getModelView( void ) const
{
	return modelView;
}


glm::mat4 Matrices::getProjection( void ) const
{
	return projection;
}