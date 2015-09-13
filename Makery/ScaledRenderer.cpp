#include "stdafx.h"
#include "ScaledRenderer.h"

namespace Makery
{
	bool ScaledRenderer::moveTo(Point position)
	{
		Point scaledPosition(position.x * scale,
			position.y * scale);
		return base->moveTo(scaledPosition);
	}

	bool ScaledRenderer::lineTo(Point position)
	{
		Point scaledPosition(position.x * scale,
			position.y * scale);
		return base->lineTo(scaledPosition);
	}

	bool ScaledRenderer::arcAt(Point centre,
		float radius, float startAngle, float endAngle)
	{
		Point scaledCentre(centre.x * scale,
			centre.y * scale);
		return base->arcAt(scaledCentre,
			radius * scale, startAngle, endAngle);
	}

	bool ScaledRenderer::ellipse(Point bottomLeft, Point topRight)
	{
		Point scaledBottomLeft(bottomLeft.x * scale,
			bottomLeft.y * scale);
		Point scaledTopRight(topRight.x * scale,
			topRight.y * scale);
		return base->ellipse(scaledBottomLeft, scaledTopRight);
	}
}