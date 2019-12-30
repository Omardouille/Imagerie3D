#include "ModelsManager.h"
using namespace Engine;
using namespace Managers;
using namespace Rendering;

ModelsManager::ModelsManager()
{
}

ModelsManager::~ModelsManager()
{
	if (!gameModelList.empty()) {
		for (auto model : gameModelList)
		{
			delete model.second;
		}
		gameModelList.clear();
	}
}

void ModelsManager::deleteModel(const std::string& gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject& ModelsManager::getModel(const std::string& gameModelName) const
{
	return (*gameModelList.at(gameModelName));
}

const std::map<std::string, IGameObject*> Engine::Managers::ModelsManager::getAllModel() const
{
	return gameModelList;
}

void Engine::Managers::ModelsManager::setModel(const std::string & gameModelName, IGameObject* gameObject)
{
	gameModelList[gameModelName.c_str()] = gameObject;
}

void ModelsManager::update()
{
	for (auto model : gameModelList)
	{
		model.second->update();
	}
}

void ModelsManager::draw()
{
	for (auto model : gameModelList)
	{
		model.second->draw();
	}
}

void ModelsManager::draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{
	for (auto model : gameModelList)
	{
		model.second->draw(projectionMatrix, viewMatrix);
	}
}