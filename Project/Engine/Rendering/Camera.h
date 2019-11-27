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
			void KeyPressed(const unsigned char key);
			void MouseMove(int x, int y, int width, int height);
			void MousePressed(int button, int state, int x, int y);

		private:
			float roll, pitch, yaw;
			glm::vec3 eyeVector;

			glm::mat4 viewMatrix;

			bool isMousePressed;
			glm::vec2 mousePosition;

			float key_roll, key_pitch, key_yaw;
			glm::quat camera_quat;

		};

	}
}