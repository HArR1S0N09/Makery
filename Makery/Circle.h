
#pragma once

#include "Drawable.h"
#include "Point.h"

namespace Makery
{
	/// <summary>Shape made of a circle at specified position and with given radius</summary>
	struct Circle : Drawable
	{
		/// <summary>Rescale the circle when the window resizes</summary>
		static void WindowDimensionsChangedHandler(Drawable *thisObject,
			float scaleX, float scaleY);

		/// <summary>Position for the centre of the circle</summary>
		Point centre;

		/// <summary>Radius for the circle</summary>
		float radius;

		Point orignalCentre;

		float originalRadius;

		bool isEllipse;

		Point bottomLeft;

		Point topRight;

		/// <summary>Initialises a new instance of a Circle</summary>
		Circle(Point circleCentre, float circleRadius);

		Circle(const Circle* other);

		virtual ~Circle();

		bool free(void);

		Drawable* copy(void);

		/// <summary>Draws the circle at the specified position and with the given radius</summary>
		bool draw(Renderer& renderer);
	};
}
