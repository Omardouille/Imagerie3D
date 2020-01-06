#pragma once
#include "Cube.h"
#include <Engine/MEngine.h>
#include "Chunk.h"
using namespace Engine;
class ChunkRenderer : public Model
{
public:
	ChunkRenderer();
	~ChunkRenderer();

	

	void create(int taille, int x=0, int y=0, int z=0);
	void create(Chunk*);
	virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;

	std::vector<glm::vec3> getWorld();

	std::vector<Engine::Rendering::VertexFormat> vertices;
	int taille;

};

