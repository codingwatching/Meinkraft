#include "BlockTextureManager.h"

#include <array>

BlockTextureManager::BlockTextureManager()
{
	registerTextures();
	
	glCreateBuffers(1, &_texturesBuffer);
	
	std::array<GLuint64, std::numeric_limits<uint8_t>::max()> textureHandles{};
	for (const auto& [id, texture] : _textures)
	{
		textureHandles[static_cast<uint8_t>(id)] = texture.getBindlessHandle();
	}
	glNamedBufferStorage(_texturesBuffer, textureHandles.size() * sizeof(uint8_t), textureHandles.data(), 0);
}

BlockTextureManager::~BlockTextureManager()
{
	glDeleteBuffers(1, &_texturesBuffer);
}

void BlockTextureManager::registerTextures()
{
	_textures.emplace(BlockTextureId::DIRT, "dirt");
	_textures.emplace(BlockTextureId::GRASS_SIDE, "grass_side");
	_textures.emplace(BlockTextureId::GRASS_TOP, "grass_top");
	_textures.emplace(BlockTextureId::IRON, "iron");
	_textures.emplace(BlockTextureId::STONE, "stone");
	_textures.emplace(BlockTextureId::WOOD, "wood");
}

GLuint BlockTextureManager::getBuffer() const
{
	return _texturesBuffer;
}