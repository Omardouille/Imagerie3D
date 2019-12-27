#pragma once
#include "Cube2.h"
#include <Engine/MEngine.h>
using namespace Engine;
class Goal : public Model
{
public:
	Goal();
	~Goal();

	void create(int x, int y, int z);
	virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;

	glm::vec3 getPosition();

private:
	glm::vec3 position;
};

