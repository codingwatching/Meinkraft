#pragma once

#include <Meinkraft/Rendering/RenderPass/RenderPass.h>
#include <memory>

class Renderer
{
public:
	Renderer();

	void render();

private:
	std::unique_ptr<RenderPass> _chunksPass;
	std::unique_ptr<RenderPass> _skyboxPass;
};