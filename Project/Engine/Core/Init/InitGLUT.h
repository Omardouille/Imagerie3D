#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include <iostream>
#include "InitGLEW.h"
#include "IListerner.h"
#include "../../Rendering/Camera.h"
namespace Engine {
	namespace Core {
		namespace Init {
			class InitGLUT
			{
			public:
				static void init(const Core::WindowInfo& window, const Core::ContextInfo& context, const Core::FramebufferInfo& framebufferInfo);
				static void run();
				static void close();
				static void setListener(Core::IListener* iListener);
				static void setCamera(Rendering::Camera* cam);

				void enterFullscreen();
				void exitFullscreen();

				static void printOpenGLInfo(const Core::WindowInfo& windowInfo, const Core::ContextInfo& context);
			private:
				static Core::IListener* listener;
				static Core::WindowInfo windowInformation;
				static Rendering::Camera* camera;
				static void idleCallback(void);
				static void displayCallback(void);
				static void reshapeCallback(int width, int height);
				static void closeCallback();
				static void keyboardCallback(unsigned char key, int x, int y);
				static void mousePressedCallback(int button, int state, int x, int y);
				static void mouseMovedCallback(int x, int y);
			};

		}
	}
}