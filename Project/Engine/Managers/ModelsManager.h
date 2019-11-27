#pragma once
#include <map>
#include "ShaderManager.h"
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"
//#include "../Rendering/Models/Cube.h"


namespace Engine {
	using namespace Rendering;
	namespace Managers
	{
		class ModelsManager
		{
		public:
			ModelsManager();
			~ModelsManager();

			void draw();
			void draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix);
			void update();
			void deleteModel(const std::string& gameModelName);
			const IGameObject& getModel(const std::string& gameModelName) const;
			void setModel(const std::string& gameModelName, IGameObject* gameObject);

		private:
			std::map<std::string, IGameObject*> gameModelList;
		};
	}
}