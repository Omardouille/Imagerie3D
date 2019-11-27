#pragma once
#include "Core\Init\InitGLUT.h"
#include "Managers/SceneManager.h"
using namespace Engine;
using namespace Core;
using namespace Init;
int main(int argc, char **argv)
{
	WindowInfo window(std::string("in2gpu OpenGL Beginner Tutorial "),
		400, 200,//position
		800, 600, //size
		true);//reshape

	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	InitGLUT::init(window, context, frameBufferInfo);

	IListener* scene = new Managers::SceneManager();
	Init::InitGLUT::setListener(scene);

	InitGLUT::run();
	delete scene;
	return 0;
}



/*
#include <iostream>

#include "Chunk.h"
#include "Managers/ShaderManager.h"
#include "Core/GameModels.h"

using namespace Managers;

ShaderManager* shaderManager;
Models::GameModels* gameModels;
GLuint program;

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0.0, 1.0);

	glBindVertexArray(gameModels->GetModel("triangle1"));

	//use the created program
	glUseProgram(program);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glutSwapBuffers();
}

void closeCallback()
{

	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init() {
	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	//load and compile shaders
	shaderManager = new ShaderManager();
	char vertexShad[]{ "Shaders/VertexShader.glsl" }, fragShad[]{ "Shaders/FragmentShader.glsl" };
	shaderManager->CreateProgram("colorShader",vertexShad, fragShad);
	program = ShaderManager::GetShader("colorShader");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glewInit();

	Init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback);

	glutMainLoop();

	delete gameModels;
	delete shaderManager;
	glDeleteProgram(program);

	return 0;
}
*/