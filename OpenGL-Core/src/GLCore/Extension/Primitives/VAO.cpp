#include "glpch.hpp"
#include "VAO.hpp"

namespace GLCore {
	

	void VAO::create() {
		glGenVertexArrays(1, & VAOID);
	}
	void VAO::bind() {
		glBindVertexArray(VAOID);
	}
	void VAO::unbind() {
		glBindVertexArray(0);
	}
	void VAO::destroy() {
		glDeleteVertexArrays(1, &VAOID);
	}
}