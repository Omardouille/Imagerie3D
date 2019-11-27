#pragma once
#include <vector>
#include <map>
#include "../IGameObject.h"
namespace Engine {
	namespace Rendering
	{
		namespace Models
		{
			class Model :public IGameObject
			{
			public:
				Model();
				virtual ~Model();

				virtual void draw() override;
				virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override;
				virtual void update() override;
				virtual void setProgram(GLuint shaderName) override;
				virtual void destroy() override;

				virtual GLuint getVao() const override;
				virtual const std::vector<GLuint>& getVbos() const override;

				virtual const GLuint getTexture(std::string textureName) const override;
				virtual void setTexture(std::string textureName, GLuint texture) override;

			protected:
				GLuint vao;
				GLuint program;
				std::vector<GLuint> vbos;
				std::map<std::string, GLuint> textures;
			};
		}
	}
}