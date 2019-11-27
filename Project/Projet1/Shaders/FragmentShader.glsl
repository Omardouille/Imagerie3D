//fragment shader
#version 450 core
 
layout(location = 0) out vec4 out_color;
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
 
in vec2 texcoord;

in flat int t;
 
void main()
{
	vec4 color;

	if( t==1 ){
		color = texture(texture2,(texcoord));
	}
	else if(t==2 ){
		color = texture(texture3,(texcoord));
	}
	else {
		color = texture(texture1, texcoord);
	}
	out_color = color;
}