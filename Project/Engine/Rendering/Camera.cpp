#include "Camera.h"
#include <algorithm>
#include <string>
#include <iostream>

using namespace Engine;
using namespace Rendering;

Camera::Camera()
{
	isMousePressed = false;
	
	mousePosition = glm::vec2(0.0f, 0.0f);
	yaw = 0.0f;
	pitch = 0.0f;
	roll = 0.0f;
	/*viewMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 0.0f, 10.0f, 1.0f);*/
	cameraPos = glm::vec3(0.0f, 4.0f, 0.0f);
	canMove = true;
	oldCameraPos = cameraPos;
	updateView();
}


Camera::~Camera()
{
}

std::string cardinal(float yaw) {
	float degrees = yaw * (180.0 / 3.141592653589793238463);
	if ((degrees <= 45 && degrees >= -45) || degrees < -315 || degrees > 315)
		return "north";
	else if ((degrees <= -45 && degrees >= -135) || (degrees >= 225 && degrees <= 315))
		return "east";
	else if ((degrees <= -135 && degrees >= -225) || (degrees >= 135 && degrees <= 225))
		return "south";
	else if ((degrees <= -225 && degrees >= -315) || (degrees >= 45 && degrees <= 135))
		return "west";
	return "null";
}

void Camera::updateView()
{
	
	//roll can be removed from here. because is not actually used in FPS camera3
	glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

	if(yaw > 6.0f || yaw < -6.0f)
		yaw = 0.0f;
	std::string c = cardinal(yaw);
	//float degrees = yaw * (180.0 / 3.141592653589793238463);
	//std::cout << "yaw: " << degrees << " c : " << c << std::endl;

	//roll, pitch and yaw are used to store our angles in our class
	matRoll = glm::rotate(matRoll, roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));
	//order matters
	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	if(!canMove)//collision
		cameraPos = oldCameraPos;
	translate = glm::translate(translate, -cameraPos);
	
	viewMatrix = rotate * translate;

	//std::cout << "x: " << cameraPos.x << " y: " << cameraPos.y << " z: " << cameraPos.z << " old " << "x: " << oldCameraPos.x << " y: " << oldCameraPos.y << " z: " << oldCameraPos.z << std::endl;
}

glm::mat4 Camera::getViewMatrix() const
{
	return viewMatrix;
}

glm::vec3 Camera::getCameraPos() const
{
	return this->cameraPos;
}

void Camera::KeyPressed(const unsigned char key)
{
	
	float dx = 0; //how much we strafe on x
	float dz = 0; //how much we walk on z
	switch (key)
	{
	case 'z':
	{
		dz = 2;
		break;
	}

	case 's':
	{
		dz = -2;
		break;
	}
	case 'q':
	{
		dx = -2;
		break;
	}

	case 'd':
	{
		dx = 2;
		break;
	}
	default:
		break;
	}

	//get current view matrix,
	glm::mat4 mat = getViewMatrix();
	//row major
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	
	float oldY = cameraPos.y;
	oldCameraPos = cameraPos;
	

	float speed = 0.12f;//how fast we move
	
	if (canMove) {
		cameraPos += (dz * forward + dx * strafe) * speed;
		cameraPos.y = oldY;
	}
	else {
		//if ground
		//cameraPos.y += speed;
		
	}
	
	//update the view matrix
	updateView();
	
}

void Camera::MouseMove(int x, int y, int width, int height)
{
	
	if (isMousePressed == false)
		return;
	//always compute delta
	//mousePosition is the last mouse position
	
	glm::vec2 mouse_delta = mousePosition - glm::vec2(x, y) ;

	const float mouseX_Sensitivity = 0.0020f;
	const float mouseY_Sensitivity = 0.0020f;
	//note that yaw and pitch must be converted to radians.
	//this is done in UpdateView() by glm::rotate
	yaw += mouseX_Sensitivity * mouse_delta.x;
	pitch += mouseY_Sensitivity * mouse_delta.y;

	if (pitch > 1.55334f) //90°
		pitch = 1.55334f;
	if (pitch < -1.55334f)
		pitch = -1.55334f;

	mousePosition = glm::vec2(x, y);
	updateView();
}

void Camera::MousePressed(int button, int state, int x, int y)
{
	
	if (state == GLUT_UP)
	{
		isMousePressed = false;
	}
	if (state == GLUT_DOWN)
	{
		isMousePressed = true;
		mousePosition.x = x;
		mousePosition.y = y;
	}
}

void Engine::Rendering::Camera::setCanMove(bool b)
{
	canMove = b;
}

void Engine::Rendering::Camera::setPosition(float x, float y, float z)
{
	cameraPos = glm::vec3(x, y, z);
}
