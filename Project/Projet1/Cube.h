#pragma once
//#include <Engine\Rendering\Models\Model.h>
#include <Engine/Rendering/Models/Model.h>
#include<time.h>
#include<stdarg.h>
using namespace Engine::Rendering::Models;

class Cube : public Model
{
public:
	Cube();
	~Cube();

	void create(float x = 0, float y = 0, float z = 0, bool oneTexture = true, bool front = true, bool right = true, bool back = true, bool left = true, bool up = true, bool bot = true);
	std::vector<Engine::Rendering::VertexFormat> vertices;
private:
	
	time_t timer;
	bool oneTexture;
};