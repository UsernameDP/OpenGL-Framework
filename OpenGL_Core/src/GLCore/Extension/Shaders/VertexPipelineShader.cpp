#include "pch.hpp"
#include "VertexPipelineShader.hpp"

namespace GLCore::Extension::Shaders {
	VertexPipelineShader::VertexPipelineShader(
		const std::string& name, 
		const std::string& vertPath, 
		const std::string& fragPath) : Shader(name)
	{ 
		addPrimitiveShader(GL_VERTEX_SHADER, vertPath);
		addPrimitiveShader(GL_FRAGMENT_SHADER, fragPath);
	}
}