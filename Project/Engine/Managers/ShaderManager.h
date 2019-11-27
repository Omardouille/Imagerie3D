#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <glew/glew.h>
#include <freeglut/freeglut.h>
namespace Engine {
	namespace Managers {
		class ShaderManager
		{

		private:
			std::string readShader(const std::string& filename);
			GLuint createShader(GLenum shaderType, const std::string& source, const std::string& shaderName);
			static std::map<std::string, GLuint> programs;

		public:
			ShaderManager();
			~ShaderManager();
			void createProgram(const std::string& shaderName, const std::string& VertexShaderFilename, const std::string& FragmentShaderFilename);
			static const GLuint getShader(const std::string&);
		};

	}
}