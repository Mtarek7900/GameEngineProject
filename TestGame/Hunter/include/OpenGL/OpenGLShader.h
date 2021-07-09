#pragma once

#include "Shader.h"


#define GLFW_INCLUDE_NONE
#include "glfw\glfw3.h"
#include "glad\glad.h"

namespace Hunter
{
	class OpenGLShader : public Shader
	{
	public:
		virtual bool Load(const std::string& vertexSource, const std::string& fragmentFile) override;
		virtual void Use() override;

		virtual void SetVec2Int(const std::string& uniformName, int val1, int val2) override;
	private:
		unsigned int mShaderProgram{ 0 };

	};
}