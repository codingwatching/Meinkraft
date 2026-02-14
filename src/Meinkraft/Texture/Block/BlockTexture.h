#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <string>

class BlockTexture
{
public:
	explicit BlockTexture(const std::string& name);

	BlockTexture(const BlockTexture& other) = delete;
	BlockTexture& operator=(const BlockTexture& other) = delete;

	BlockTexture(BlockTexture&& other);
	BlockTexture& operator=(BlockTexture&& other);

	~BlockTexture();

	GLuint64 getBindlessHandle() const;

private:
	glm::ivec2 _size;
	GLuint64 _bindlessHandle;

	GLuint _handle;

	static int calculateMipmapCount(const glm::ivec2& size);
};