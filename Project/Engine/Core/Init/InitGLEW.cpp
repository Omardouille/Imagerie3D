#include "InitGLEW.h"

using namespace Engine;
using namespace Core;
using namespace Init;

void InitGLEW::Init() {

	glewExperimental = true;
	if (glewInit() == GLEW_OK)
	{
		glDisable(GL_CULL_FACE);
		std::cout << "GLEW: Initialize" << std::endl;
	}

	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << "GLEW GL_VERSION_4_5 is 4.5\n ";
	}
	else
	{
		std::cout << " GLEW GL_VERSION_4_5 not supported\n ";
	}
}