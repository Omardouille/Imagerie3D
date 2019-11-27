#pragma once
#include "Core\Init\InitGLUT.h"
#include "Managers\SceneManager.h"
#include "Rendering/Camera.h"

namespace Engine
{
	class MEngine
	{

	public:
		MEngine();
		~MEngine();

		//OpenGL and manager init
		bool init();

		//Loop
		void run();

		//Getters
		Managers::SceneManager*  getSceneManager()  const;
		Managers::ShaderManager* getShaderManager() const;
		Managers::ModelsManager* getModelsManager() const;

		TextureLoader* getTextureLoader() const;

	private:
		Managers::SceneManager* m_scene_manager;
		Managers::ShaderManager* m_shader_manager;
		Managers::ModelsManager* m_models_manager;

		TextureLoader* m_texture_loader;
	};
}