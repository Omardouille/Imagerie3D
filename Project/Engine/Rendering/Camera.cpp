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
	cameraPos = glm::vec3(0.0f, 10.0f, 0.0f);
	canMove = true;
	oldCameraPos = cameraPos;
	velocity = 0.0f;
	canJump = true;
	canJump2 = true;
	height = cameraPos.y;
	speed = 0.02f;
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
	glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

	if(yaw > 6.0f || yaw < -6.0f)
		yaw = 0.0f;
	//std::string c = cardinal(yaw);
	//std::cout << "yaw: " << degrees << " c : " << c << std::endl;

	matRoll = glm::rotate(matRoll, roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);

	if(!canMove)//collision
		cameraPos = oldCameraPos;

	//gavity
	velocity += gravity * 0.001f;
	cameraPos.y += velocity;
	if (cameraPos.y < height && canJump2) {
		cameraPos.y = height;
		canJump = true;
	}
	handleKeys();
	translate = glm::translate(translate, -cameraPos);
	
	viewMatrix = rotate * translate;
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
	if (key == 'z')
		keyarr['z'] = PUSHED;
	if (key == 's')
		keyarr['s'] = PUSHED;
	if (key == 'q')
		keyarr['q'] = PUSHED;
	if (key == 'd')
		keyarr['d'] = PUSHED;
	if (key == ' ')
		keyarr[' '] = PUSHED;
	if(key == 'r')
		cameraPos = glm::vec3(0.0f, 4.0f, 0.0f);
}

void Engine::Rendering::Camera::KeyUped(const unsigned char key)
{
	if (key == 'z')
		keyarr['z'] = NOTPUSHED;
	if (key == 's')
		keyarr['s'] = NOTPUSHED;
	if (key == 'q')
		keyarr['q'] = NOTPUSHED;
	if (key == 'd')
		keyarr['d'] = NOTPUSHED;
	if (key == ' ')
		keyarr[' '] = NOTPUSHED;
}

void Engine::Rendering::Camera::KeySpec(int key)
{
}

void Engine::Rendering::Camera::KeyUpSpec(int key)
{
}

void Engine::Rendering::Camera::handleKeys()
{
	float dx = 0;
	float dz = 0;
	if (keyarr['z'] == PUSHED)
	{
		dz = 2;
	}

	if (keyarr['s'] == PUSHED)
	{
		dz = -2;
	}
	if (keyarr['q'] == PUSHED)
	{
		dx = -2;
	}

	if (keyarr['d'] == PUSHED)
	{
		dx = 2;
	}
	if (keyarr[' '] == PUSHED)//space
	{
		if (canJump) {
			velocity = 0.4f;
			canJump = false;
		}
	}

	//get current view matrix,
	glm::mat4 mat = getViewMatrix();
	//row major
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	oldCameraPos = cameraPos;


	if (canMove) {
		cameraPos += (dz * forward + dx * strafe) * speed;
		cameraPos.y = oldCameraPos.y;
	}
}


void Camera::MouseMove(int x, int y, int width, int height)
{
	
	if (isMousePressed == false)
		return;

	//mousePosition is the last mouse position
	glm::vec2 mouse_delta = mousePosition - glm::vec2(x, y) ;

	const float mouseX_Sensitivity = 0.0020f;
	const float mouseY_Sensitivity = 0.0020f;

	yaw += mouseX_Sensitivity * mouse_delta.x;
	pitch += mouseY_Sensitivity * mouse_delta.y;

	if (pitch > 1.55334f) //90°
		pitch = 1.55334f;
	if (pitch < -1.55334f)
		pitch = -1.55334f;

	mousePosition = glm::vec2(x, y);
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

void Engine::Rendering::Camera::setHeight(int y)
{
	height = y + 4;
}

