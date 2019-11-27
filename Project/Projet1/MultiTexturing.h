#pragma once
#include <Engine\Rendering\Models\Model.h>
#include <chrono>

using namespace Engine::Rendering::Models;

typedef std::chrono::high_resolution_clock hiResTime;
typedef std::chrono::milliseconds miliSec;
typedef std::chrono::duration<float> deltaTime;

class Multitexturing : public Model {
public:
	Multitexturing();
	~Multitexturing();

	// Will generate the geometry, indices, and UVs for a sphere (same structure as the old gluSphere - "stacks and slices")
	// We could've used the cube and "morphed" it into a sphere in the vertex shader 
	// However, that is out of the scope of this tutorial
	void createSphere(float radius, unsigned int rings, unsigned int sectors);

	// Drawing a static sphere. We'll let the frag shader do the UV rotation this time
	virtual void draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;

private:
};