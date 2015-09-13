#pragma once

#include "Drawable.h"

namespace Makery
{
	struct Rectangle : Drawable
	{
		Point bottomLeft;

		Point topRight;

		Point originalBottomLeft;

		Point originalTopRight;

		Rectangle(Point bottomLeftCorner, Point topRightCorner);

		Rectangle(const Rectangle* other);

		Drawable* copy(void);

		virtual ~Rectangle();

		bool free(void);

		/// <summary>Draws the polygon using the array of corners</summary>
		bool draw(Renderer& renderer);

		static void WindowDimensionsChangedHandler(Drawable *thisObject,
			float scaleX, float scaleY);
	};
}
