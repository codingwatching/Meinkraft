#pragma once

#include "Meinkraft/Block/BlockType.h"
#include "Meinkraft/BlockId.h"
#include "Meinkraft/GL/VertexData.h"

#include <array>
#include <functional>
#include <memory>
#include <string_view>
#include <vector>

struct VertexGenerationInfo;

struct BlockDefinition
{
	using VertexGenerator = void(std::vector<VertexData>& output, glm::u8vec3 pos, BlockType xp1, BlockType xm1, BlockType yp1, BlockType ym1, BlockType zp1, BlockType zm1, const std::unordered_map<std::string_view, BlockTextureId>& textures);

	BlockType type;
	VertexGenerator* vertexGenerator;
	std::unordered_map<std::string_view, BlockTextureId> textures;
};