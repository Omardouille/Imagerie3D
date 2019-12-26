#pragma once
//#include <Engine\Rendering\Models\Model.h>
#include <Engine/Rendering/Models/Model.h>
#include<time.h>
#include<stdarg.h>
using namespace Engine::Rendering::Models;

class Cube2 : public Model
{
public:
	Cube2();
	~Cube2();

	void create(float x = 0, float y = 0, float z = 0, bool oneTexture = true);
	void create(float x = 0, float y = 0, float z = 0, bool oneTexture = true, bool front = true, bool right = true, bool back = true, bool left = true, bool up = true, bool bot = true);
	//virtual void draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;
	//virtual void update() override final;
	std::vector<Engine::Rendering::VertexFormat> vertices;
private:
	
	glm::vec3 position;
	glm::vec3 rotation, rotation_speed;
	glm::vec3 rotation_sin;
	time_t timer;
	bool oneTexture;
};