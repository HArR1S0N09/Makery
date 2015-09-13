
#pragma once

#include "Drawable.h"
#include "Point.h"

namespace Makery
{
	/// <summary>Shape made of closed multi-line segments (no gaps, first point is different from the last point)</summary>
	struct Polygon : Drawable
	{
		/// <summary>Rescale the polygon when the window resizes</summary>
		static void WindowDimensionsChangedHandler(Drawable *thisObject,
			float scaleX, float scaleY);

		/// <summary>Array of positions for all the corners of the polygon</summary>
		Point* corners = NULL;

		/// <summary>Number of positions for all the corners of the polygon</summary>
		size_t cornerCount = 0;

		/// <summary>Original corners, before any window resize happened</summary>
		Point* originalCorners = NULL;

		/// <summary>Initialises a new instance of a Polygon</summary>
		Polygon(Point* polygonCorners, size_t polygonCornerCount);

		Polygon(const Polygon* other);

		Drawable* copy(void);

		virtual ~Polygon();

		bool free(void);

		/// <summary>Draws the polygon using the array of corners</summary>
		bool draw(Renderer& renderer);
	};
}
