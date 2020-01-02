#include "SceneManager.h"
using namespace Engine;
using namespace Managers;

SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);
	
	/*viewMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 0.0f, 10.0f, 1.0f);*/

	m_camera = new Camera();
	Engine::Core::Init::InitGLUT::setCamera(m_camera);
	viewMatrix = m_camera->getViewMatrix();
	m_collision = new Interaction::Collision();
}

SceneManager::~SceneManager()
{
}

void SceneManager::notifyBeginFrame()
{
	std::map<std::string, IGameObject*> models = modelsManager->getAllModel();
	glm::vec3 camPos = m_camera->getCameraPos();
	m_world.clear();
	for (auto const& m : models)
	{
		glm::vec3 p = m.second->position;
		if (std::sqrt(std::pow(camPos.x - p.x*2, 2) + std::pow(camPos.z - p.z*2, 2)) > 100) {//rendering view
			m.second->active = false;
		}
		else {
			m.second->active = true;
			m_world.insert(std::end(m_world), std::begin(m.second->world), std::end(m.second->world));
		}
	}
	modelsManager->update();
	viewMatrix = m_camera->getViewMatrix();
	bool c = m_collision->detectCollision(m_camera->getCameraPos(), m_world);
	m_camera->setCanMove(!c);
	float y = getHeight(m_camera->getCameraPos().x, m_camera->getCameraPos().y, m_camera->getCameraPos().z);
	m_camera->setHeight(y);
	bool win = m_collision->AABBtoAABB(m_camera->getCameraPos(), goalPosition);
	if (win) {
		std::cout << "Vous avez gagné !" << std::endl;
		Sleep(3000);
		glutDestroyWindow(glutGetWindow());
	}
	m_camera->updateView();

}

void SceneManager::notifyDisplayFrame()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	modelsManager->draw();
	modelsManager->draw(projectionMatrix, viewMatrix);
	
}

void SceneManager::notifyEndFrame()
{
}

void SceneManager::notifyReshape(int width,int height,int previous_width,int previous_height)
{
	float ar = (float)glutGet(GLUT_WINDOW_WIDTH) /	(float)glutGet(GLUT_WINDOW_HEIGHT);
	float angle = 45.0f, near1 = 0.1f, far1 = 2000.0f;

	projectionMatrix[0][0] = 1.0f / (ar * tan(angle / 2.0f));
	projectionMatrix[1][1] = 1.0f / tan(angle / 2.0f);
	projectionMatrix[2][2] = (-near1 - far1) / (near1 - far1);
	projectionMatrix[2][3] = 1.0f;
	projectionMatrix[3][2] = 2.0f * near1 * far1 / (near1 - far1);
}

float Engine::Managers::SceneManager::getHeight(float x, float y, float z)
{
	float height = -100;
	bool find = false;
	int i = 0;
	int xRound = round(x / 2) * 2;
	int zRound = round(z / 2) * 2;
	while (!find && i<m_world.size()) {
		if ((int)m_world[i].x == xRound && (int)m_world[i].z == zRound) {
			find = true;
			height = (int)m_world[i].y;
		}
		i++;
	}
	if (y < height) {
		height = y;
		height -= 4;
		m_camera->canJump2 = false;
	}
	else
		m_camera->canJump2 = true;
	
	return height;
}

Camera * Engine::Managers::SceneManager::getCamera() const
{
	return m_camera;
}

std::vector<glm::vec3> Engine::Managers::SceneManager::getWorld()
{
	return m_world;
}

void Engine::Managers::SceneManager::setWorld(std::vector<glm::vec3> w)
{
	m_world = w;
}

void Engine::Managers::SceneManager::setGoalPosition(glm::vec3 position)
{
	goalPosition = position;
}

void SceneManager::setModelsManager(Managers::ModelsManager*& models_m)
{
	modelsManager = models_m;
}

void Engine::Managers::SceneManager::setViewMatrix(glm::mat4 vM)
{
	viewMatrix = vM;
}
