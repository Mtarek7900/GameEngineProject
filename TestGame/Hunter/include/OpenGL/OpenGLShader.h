#pragma once

#include "Shader.h"
#include "HunterCentral.h"


#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>
#include <glad/glad.h>

namespace Hunter
{
	class OpenGLShader : public Shader
	{
	public:
		virtual bool Load(const std::string& vertexFile, const std::string& fragmentFile) override;
		virtual void Use() override;

		virtual void SetVec2Int(const std::string& uniformName, int val1, int val2) override;
		virtual ~OpenGLShader() override;
	private:
		unsigned int CompileVertexShader(const std::string& vertexCode);
		unsigned int CompileFragmentShader(const std::string& fragmentCode);
		
		unsigned int mShaderProgram{ 0 };

	};
}