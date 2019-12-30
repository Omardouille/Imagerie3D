#include "MEngine.h"
using namespace Engine;
using namespace Core;

MEngine::MEngine()
{
	windowName = std::string("OpenGL Window");
}

MEngine::MEngine(std::string name)
{
	windowName = name;
}


//You can set params for init
bool MEngine::init()
{
	WindowInfo window(windowName,
		400, 200,
		800, 600, true);
	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);

	Init::InitGLUT::init(window, context, frameBufferInfo);

	m_scene_manager = new Managers::SceneManager();

	Init::InitGLUT::setListener(m_scene_manager);

	m_shader_manager = new Managers::ShaderManager();

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
	m_scene_manager->setGoalPosition(goalPosition);
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


void Engine::MEngine::setWorld(std::vector<glm::vec3> w)
{
	world = w;
}

void Engine::MEngine::setGoalPosition(glm::vec3 position)
{
	goalPosition = position;
}

MEngine::~MEngine()
{
	if (m_scene_manager)
		delete m_scene_manager;

	if (m_shader_manager)
		delete m_shader_manager;

	if (m_models_manager)
		delete m_models_manager;
}