#pragma once
#include "Cube2.h"
#include <Engine/MEngine.h>
//#include <soil/SOIL.h>
using namespace Engine;
class Chunk2 : public Model
{
public:
	Chunk2();
	~Chunk2();

	void create(int taille, MEngine* engine);
	virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;

	//std::vector<Cube2*> listCubes;
	std::vector<Engine::Rendering::VertexFormat> vertices;
	int taille;

};

