#pragma once
#include <stdlib.h>
#include <vector>
#include <Engine/Rendering/Models/Model.h>
using namespace Engine::Rendering::Models;
class Skybox : public Model
{
public:
	Skybox(float size);
	~Skybox();
	virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;
private:
	unsigned int loadCubemap(std::vector<std::string> faces);
	unsigned int textureID;
};

