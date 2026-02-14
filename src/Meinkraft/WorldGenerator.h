#pragma once

#include "Meinkraft/BlockContainer.h"
#include "Meinkraft/MountainGenerator.h"

class WorldGenerator
{
public:
	BlockContainer generateMountains(int x, int y, int z);

private:
	MountainGenerator _mountains;
};
