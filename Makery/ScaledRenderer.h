
#pragma once

#include "Renderer.h"

namespace Makery
{
	/// <summary>Draws shapes at a scale</summary>
	struct ScaledRenderer : Renderer
	{
		/// <summary>Base renderer (unscaled)</summary>
		Renderer* base;

		/// <summary>Scale to draw shapes at</summary>
		float scale;

		ScaledRenderer(Renderer* baseRenderer, float scaleFactor)
		{
			base = baseRenderer;
			scale = scaleFactor;
		}

		/// <summary>Moves the drawing pen to the specified position, scaled, do not draw</summary>
		bool moveTo(Point position);

		/// <summary>Draws a line from the current position to the specified position, scaled, and move the current position to the end point</summary>
		bool lineTo(Point position);

		/// <summary>Draws a circular arc (angles in radians, full circle at 2 pi)</summary>
		bool arcAt(Point centre,
			float radius, float startAngle, float endAngle);

		/// <summary>Draws an ellipse using the specified positions</summary>
		bool ellipse(Point bottomLeft, Point topRight);
	};
}
