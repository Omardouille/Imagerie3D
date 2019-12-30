#pragma once
#include <map>
#include "ShaderManager.h"
#include "../Rendering/IGameObject.h"


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
			const std::map<std::string, IGameObject*> getAllModel() const;
			void setModel(const std::string& gameModelName, IGameObject* gameObject);

		private:
			std::map<std::string, IGameObject*> gameModelList;
		};
	}
}