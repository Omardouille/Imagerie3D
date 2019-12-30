#include "InitGLUT.h"
using namespace Engine;
using namespace Core;
using namespace Init;

Rendering::Camera* InitGLUT::camera = NULL;
Core::IListener* InitGLUT::listener = NULL;
Core::WindowInfo InitGLUT::windowInformation;

void InitGLUT::init(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo,
	const Core::FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char fake[]{ "fake" };
	char *fakeargv[] = { fake, NULL };
	glutInit(&fakeargc, fakeargv);
	windowInformation = windowInfo;


	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.major_version, contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.position_x, windowInfo.position_y);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;
	//these callbacks are used for rendering
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	////these callbacks are used for key listening
	glutKeyboardFunc(keyboardCallback);
	glutKeyboardUpFunc(keyboardUpCallback);
	glutMouseFunc(mousePressedCallback);
	glutMotionFunc(mouseMovedCallback);
	glutPassiveMotionFunc(mouseMovedCallback);
	glutSpecialFunc(specialCallback);
	glutSpecialUpFunc(specialUpCallback);

	//init GLEW
	Init::InitGLEW::Init();

	//cleanup
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Method to display some info.
	printOpenGLInfo(windowInfo, contextInfo);
	
}

//starts the rendering Loop
void InitGLUT::run()
{
	std::cout << "GLUT:\t Start Running " << std::endl;
	glutMainLoop();
}

void InitGLUT::close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void InitGLUT::idleCallback(void)
{
	glutPostRedisplay();
}

void InitGLUT::displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1);
	if (listener)
	{
		listener->notifyBeginFrame();
		listener->notifyDisplayFrame();

		glutSwapBuffers();

		listener->notifyEndFrame();
	}
	
}

void InitGLUT::reshapeCallback(int width, int height)
{
	if (windowInformation.isReshapable == true)
	{
		if (listener)
		{
			listener->notifyReshape(width, height, windowInformation.width, windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
		glViewport(0, 0, width, height);
	}
}

void InitGLUT::closeCallback()
{
	close();
}

void InitGLUT::keyboardCallback(unsigned char key, int x, int y)
{
	if (camera) {
		camera->KeyPressed(key);
	}
}

void InitGLUT::keyboardUpCallback(unsigned char key, int x, int y)
{
	if (camera) {
		camera->KeyUped(key);
	}
}

void Engine::Core::Init::InitGLUT::mousePressedCallback(int button, int state, int x, int y)
{
	if (camera) {
		camera->MousePressed(button,state,x,y);
	}
}

void Engine::Core::Init::InitGLUT::mouseMovedCallback(int x, int y)
{
	if (camera) {
		camera->MouseMove(x, y, windowInformation.width, windowInformation.height);
	}
}

void Engine::Core::Init::InitGLUT::specialCallback(int key, int x, int y)
{
	if (camera) {
		camera->KeySpec(key);
	}
}

void Engine::Core::Init::InitGLUT::specialUpCallback(int key, int x, int y)
{
	if (camera) {
		camera->KeyUpSpec(key);
	}
}

void InitGLUT::enterFullscreen()
{
	glutFullScreen();
}

void InitGLUT::exitFullscreen()
{
	glutLeaveFullScreen();
}

void InitGLUT::printOpenGLInfo(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo) {

	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "******************************************************               ************************" << std::endl;
	std::cout << "GLUT:Initialise" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
}

void InitGLUT::setListener(Core::IListener* iListener)
{
	listener = iListener;
}

void Engine::Core::Init::InitGLUT::setCamera(Rendering::Camera * cam)
{
	camera = cam;
}