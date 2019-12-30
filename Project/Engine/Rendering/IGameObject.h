#pragma once
#include <vector>
#include <iostream>
#include <glew/glew.h>
#include <freeglut/freeglut.h>
#include "VertexFormat.h"
#include "Texture/TextureLoader.h"
namespace Engine {
	namespace Rendering
	{
		class IGameObject
		{
		public:
			virtual ~IGameObject() = 0;

			virtual void draw() = 0;
			virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) = 0;
			virtual void update() = 0;
			virtual void setProgram(GLuint shaderName) = 0;
			virtual void destroy() = 0;

			virtual GLuint getVao() const = 0;
			virtual const std::vector<GLuint>& getVbos() const = 0;

			virtual void setTexture(std::string textureName, GLuint texture) = 0;
			virtual const GLuint getTexture(std::string textureName) const = 0;

			std::vector<glm::vec3> world;
			glm::vec3 position;
			bool active;
			
		};

		inline IGameObject::~IGameObject()
		{//blank
		}
	}
}