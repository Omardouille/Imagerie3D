#include "Camera.h"

using namespace Engine;
using namespace Rendering;

Camera::Camera()
{
	isMousePressed = false;
	cameraPos = glm::vec3(0.0f, 0.0f, -10.0f);
	mousePosition = glm::vec2(0.0f, 0.0f);
	yaw = -90.f;
	pitch = 0.0f;
	roll = 0.0f;
	viewMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 0.0f, 10.0f, 1.0f);
	key_pitch = key_yaw = key_roll = 0;
}


Camera::~Camera()
{
}

void Camera::updateView()
{
	
	//roll can be removed from here. because is not actually used in FPS camera3
	glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

	//roll, pitch and yaw are used to store our angles in our class
	matRoll = glm::rotate(matRoll, roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));
	std::cout << pitch << std::endl;
	//order matters
	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -cameraPos);

	viewMatrix = rotate * translate;
	float test = viewMatrix[0][0];
	//float test = eyeVector.x;
	//printf("test : %f \n", test);
	
	
	//AVEC QUAT
	/*
	//FPS camera:  RotationX(pitch) * RotationY(yaw)
	glm::quat qPitch = glm::angleAxis(key_pitch, glm::vec3(1, 0, 0));
	glm::quat qYaw = glm::angleAxis(key_yaw, glm::vec3(0, 1, 0));
	glm::quat qRoll = glm::angleAxis(roll, glm::vec3(0, 0, 1));

	//For a FPS camera we can omit roll
	glm::quat orientation = qPitch * qYaw;
	orientation = glm::normalize(orientation);
	glm::mat4 rotate = glm::mat4_cast(orientation);

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -cameraPos);

	viewMatrix = rotate * translate;
	*/
	//Avec Quat 2
	/*
	glm::quat key_quat = glm::quat(glm::vec3(key_pitch, key_yaw, key_roll));
	//reset values
	key_pitch = key_yaw = key_roll = 0;

	//order matters,update camera_quat
	camera_quat = key_quat * camera_quat;
	camera_quat = glm::normalize(camera_quat);
	glm::mat4 rotate = glm::mat4_cast(camera_quat);

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -cameraPos);

	viewMatrix = rotate * translate;
	*/
}

glm::mat4 Camera::getViewMatrix() const
{
	return viewMatrix;
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

	const float speed = 0.12f;//how fast we move

	cameraPos += (dz * forward + dx * strafe) * speed;

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

	/*
	glm::vec2 mouse_delta = mousePosition - glm::vec2(x, y);

	//notice that we reduce the sensitvity
	const float mouseX_Sensitivity = 0.0020f;
	const float mouseY_Sensitivity = 0.0020f;

	key_yaw = mouseX_Sensitivity * mouse_delta.x;
	key_pitch = mouseY_Sensitivity * mouse_delta.y;

	mousePosition = glm::vec2(x, y);
	updateView();*/
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