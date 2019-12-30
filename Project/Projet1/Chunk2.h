#pragma once
#include "Cube2.h"
#include <Engine/MEngine.h>
#include "Chunk.h"
using namespace Engine;
class Chunk2 : public Model
{
public:
	Chunk2();
	~Chunk2();

	

	void create(int taille, int x=0, int y=0, int z=0);
	void create(Chunk*);
	virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;

	std::vector<glm::vec3> getWorld();

	//std::vector<Cube2*> listCubes;
	std::vector<Engine::Rendering::VertexFormat> vertices;
	int taille;

};

