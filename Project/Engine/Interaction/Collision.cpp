#include "Collision.h"
using namespace Engine;
using namespace Interaction;


bool Engine::Interaction::Collision::AABBtoAABB(const glm::vec3 & tBox1, const glm::vec3 & tBox2)
{
	float size = 1.0f;//size
	float sizeP = 0.12f;//largeur
	float sizeH = 3.0f;//hauteur
	return(tBox1.x + sizeP > tBox2.x - size &&
		tBox1.x - sizeP < tBox2.x + size &&
		tBox1.y + sizeH > tBox2.y - size &&
		tBox1.y - sizeH < tBox2.y + size &&
		tBox1.z + sizeP > tBox2.z - size &&
		tBox1.z - sizeP < tBox2.z + size);
}

bool Engine::Interaction::Collision::detectCollision(glm::vec3 playerPos, std::vector<glm::vec3> world)
{
	for (glm::vec3 t : world) {
		if (AABBtoAABB(playerPos, t))
			return true;//collision with world
	}
	return false;//no collision with world
}

