#include <cassert>
#include "BlockContainer.h"
#include "Helper/MathHelper.h"

void BlockContainer::setBlock(glm::u8vec3 pos, BlockType block)
{
	assert(MathHelper::between(pos.x, 0, 15));
	assert(MathHelper::between(pos.y, 0, 15));
	assert(MathHelper::between(pos.z, 0, 15));
	_blocks[posToIndex(pos)] = block;
}

BlockType BlockContainer::getBlock(glm::u8vec3 pos) const
{
	assert(MathHelper::between(pos.x, 0, 15));
	assert(MathHelper::between(pos.y, 0, 15));
	assert(MathHelper::between(pos.z, 0, 15));
	return _blocks[posToIndex(pos)];
}

int BlockContainer::posToIndex(glm::u8vec3 pos)
{
	return pos.x + pos.y * 16 + pos.z * 256;
}

glm::u8vec3 BlockContainer::indexToPos(int index)
{
	return glm::u8vec3(index % 16, (index/16) % 16, (index/256) % 16);
}
