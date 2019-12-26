#pragma once
#include "ShaderManager.h"
#include "ModelsManager.h"
#include "../Core/Init/InitGLUT.h"
#include "../Core/Init/IListerner.h"
#include "../Rendering/Camera.h"
#include "../Interaction/Collision.h"
namespace Engine {
	namespace Managers {
		class SceneManager : public Core::IListener
		{
		public:
			SceneManager();
			~SceneManager();

			virtual void notifyBeginFrame();
			virtual void notifyDisplayFrame();
			virtual void notifyEndFrame();
			virtual void notifyReshape(int width, int height, int previous_width, int previous_height);

			Camera* getCamera() const;
			void setWorld(std::vector<glm::vec3> w);

			void setModelsManager(Managers::ModelsManager*& models_manager);
			void setViewMatrix(glm::mat4 viewMatrix);
		private:
			Managers::ShaderManager* shaderManager;
			Managers::ModelsManager* modelsManager;
			glm::mat4 projectionMatrix;
			glm::mat4 viewMatrix;
			Camera* m_camera;
			Interaction::Collision* m_collision;
			std::vector<glm::vec3> m_world;
		};
	}
}