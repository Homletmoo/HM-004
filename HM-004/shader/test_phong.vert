#version 400

layout(location = 0) in vec3 i_pos;
layout(location = 1) in vec3 i_tex;
layout(location = 2) in vec3 i_normal;

out vec3 f_pos;
out vec3 f_tex;
out vec3 f_normal;

uniform mat4 u_MV;
uniform mat4 u_P;
uniform mat3 u_N;

void main( void )
{
	f_pos = vec3( u_MV * vec4( i_pos, 1.0 ) );
	f_tex = i_tex;
	f_normal = normalize( u_N * i_normal );

	gl_Position = u_P * u_MV * vec4( i_pos, 1.0 );
}
