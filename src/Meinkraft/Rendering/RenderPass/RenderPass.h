#pragma once

class RenderPass
{
public:
	RenderPass() = default;
	virtual ~RenderPass() = default;

	virtual void render() = 0;
};