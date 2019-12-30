#pragma once
#include <glm/glm.hpp>
#include <vector>
namespace Engine {
	namespace Interaction {
		class Collision
		{
		public:
			bool detectCollision(glm::vec3 playerPos, std::vector<glm::vec3> world);
			bool AABBtoAABB(const glm::vec3& tBox1, const glm::vec3& tBox2);
		};
	}
}

