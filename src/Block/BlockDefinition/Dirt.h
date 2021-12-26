#pragma once

#include "../BlockDefinition.h"

class Dirt : public BlockDefinition
{
public:
	Dirt();
	
	void genVertices(std::vector<VertexData>& vertices, glm::u8vec3 pos, BlockType xp1, BlockType xm1, BlockType yp1, BlockType ym1, BlockType zp1, BlockType zm1) override;
};
