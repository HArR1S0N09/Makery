
#pragma once

#include "Point.h"

namespace Makery
{
	/// <summary>2 pi</summary>
	const float twoPi = 6.28318530718f;

	/// <summary>Pen used to draw simple strokes on the 2D space of a computer display</summary>
	struct Renderer
	{
		/// <summary>Moves the drawing pen to the specified position, do not draw</summary>
		virtual bool moveTo(Point position) = 0;

		/// <summary>Draws a line from the current position to the specified position, and move the current position to the end point</summary>
		virtual bool lineTo(Point position) = 0;

		/// <summary>Draws a circular arc (angles in radians, full circle at 2 pi)</summary>
		virtual bool arcAt(Point centre, float radius, float startAngle, float endAngle) = 0;

		/// <summary>Draws an ellipse using the specified positions</summary>
		virtual bool ellipse(Point bottomLeft, Point topRight) = 0;

		/// <summary>Draws a circle at the specified position and with the given radius</summary>
		virtual bool circleAt(Point centre, float radius);

		/// <summary>Draws a rectangle between the specified positions</summary>
		virtual bool rectangleAt(Point bottomLeft, Point topRight);
	};
}