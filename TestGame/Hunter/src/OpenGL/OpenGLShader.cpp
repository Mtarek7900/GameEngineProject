#include <cassert>
#include "OpenGL/OpenGLShader.h"
#include <fstream>
#include <sstream>

namespace Hunter
{
	bool OpenGLShader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::ifstream vertexSource{ vertexFile };
		std::ifstream fragmentSource{ fragmentFile };

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertexSource.rdbuf();
		fShaderStream << fragmentSource.rdbuf();

		vertexSource.close();
		fragmentSource.close();

		std::string vertexCode{ vShaderStream.str() };
		std::string fragmentCode{ fShaderStream.str() };

		unsigned int vShader;
		vShader = glCreateShader(GL_VERTEX_SHADER);
		const char* cstring{ vertexCode.c_str() };
		glShaderSource(vShader, 1, &cstring, 0);
		glCompileShader(vShader);
		int success{ 0 };
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	}
	
	void OpenGLShader::Use()
	{
		assert(mShaderProgram);

		glUseProgram(mShaderProgram);
	}
	
	void OpenGLShader::SetVec2Int(const std::string& uniformName, int val1, int val2)
	{
		assert(mShaderProgram);
		
		int uniformID{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(uniformID, val1, val2);
	}

	
}