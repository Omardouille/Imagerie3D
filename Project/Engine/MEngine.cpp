#include "MEngine.h"
using namespace Engine;
using namespace Core;

MEngine::MEngine()
{

}


//You can set params for init
bool MEngine::init()
{
	WindowInfo window(std::string("OpenGL Window"),
		400, 200,
		800, 600, true);
	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);

	Init::InitGLUT::init(window, context, frameBufferInfo);

	m_scene_manager = new Managers::SceneManager();

	Init::InitGLUT::setListener(m_scene_manager);


	//this was created in  scene manager constructor, now copy here
	m_shader_manager = new Managers::ShaderManager();
	//m_shader_manager->createProgram("colorShader",		"..\\Engine\\Shaders\\VertexShader.glsl",		"..\\Engine\\Shaders\\FragmentShader.glsl");

	m_texture_loader = new TextureLoader();

	if (m_scene_manager && m_shader_manager)
	{
		m_models_manager = new Managers::ModelsManager();
		m_scene_manager->setModelsManager(m_models_manager);
	}
	else
	{
		return false;
	}

	return true;
}

//Create the loop
void MEngine::run()
{
	m_scene_manager->setWorld(world);
	Init::InitGLUT::run();
	
}

Managers::SceneManager* MEngine::getSceneManager() const
{
	return m_scene_manager;
}

Managers::ShaderManager* MEngine::getShaderManager() const
{
	return m_shader_manager;
}

Managers::ModelsManager* MEngine::getModelsManager() const
{
	return m_models_manager;
}

TextureLoader* MEngine::getTextureLoader() const
{
	return m_texture_loader;
}

void Engine::MEngine::setWorld(std::vector<glm::vec3> w)
{
	world = w;
}

MEngine::~MEngine()
{
	if (m_scene_manager)
		delete m_scene_manager;

	if (m_shader_manager)
		delete m_shader_manager;

	if (m_models_manager)
		delete m_models_manager;

	if (m_texture_loader)
		delete m_texture_loader;
}