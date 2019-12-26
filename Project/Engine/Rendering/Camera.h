#pragma once
#include <iostream>
#include <freeglut/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/quaternion.hpp>
#include "../Core/Init/IListerner.h"
namespace Engine {
	namespace Rendering {
		class Camera
		{
		public:
			Camera();
			~Camera();
			void updateView();
			glm::mat4 getViewMatrix() const;
			glm::vec3 getCameraPos() const;
			void KeyPressed(const unsigned char key);
			void MouseMove(int x, int y, int width, int height);
			void MousePressed(int button, int state, int x, int y);
			void setCanMove(bool b);
			void setPosition(float x, float y, float z);
		private:
			float roll, pitch, yaw;
			glm::vec3 cameraPos;
			glm::vec3 oldCameraPos;

			glm::mat4 viewMatrix;

			bool isMousePressed;
			glm::vec2 mousePosition;

			bool canMove;
		};
	}
}