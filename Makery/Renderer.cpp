
#include "stdafx.h"

#include "Renderer.h"

namespace Makery
{
	bool Renderer::circleAt(Point centre, float radius)
	{
		return arcAt(centre, radius, 0.0f, twoPi);
	}

	bool Renderer::rectangleAt(Point bottomLeft, Point topRight)
	{
		moveTo(bottomLeft);
		Point bottomRight(topRight.x, bottomLeft.y);
		lineTo(bottomRight);
		lineTo(topRight);
		Point topLeft(bottomLeft.x, topRight.y);
		lineTo(topLeft);
		return lineTo(bottomLeft);
	}
}