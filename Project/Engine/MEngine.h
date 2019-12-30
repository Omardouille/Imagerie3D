#pragma once
#include "Core\Init\InitGLUT.h"
#include "Managers\SceneManager.h"
#include "Rendering/Camera.h"
#include "Interaction/Collision.h"

namespace Engine
{
	class MEngine
	{

	public:
		MEngine();
		MEngine(std::string name);
		~MEngine();

		//OpenGL and manager init
		bool init();

		//Loop
		void run();

		//Getters
		Managers::SceneManager*  getSceneManager()  const;
		Managers::ShaderManager* getShaderManager() const;
		Managers::ModelsManager* getModelsManager() const;

		//Setters
		void setWorld(std::vector<glm::vec3>);
		void setGoalPosition(glm::vec3 position);

	private:
		Managers::SceneManager* m_scene_manager;
		Managers::ShaderManager* m_shader_manager;
		Managers::ModelsManager* m_models_manager;

		std::string windowName;
		std::vector<glm::vec3> world;
		glm::vec3 goalPosition;
		
	};
}