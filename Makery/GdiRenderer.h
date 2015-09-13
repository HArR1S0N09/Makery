#pragma once

#include "Renderer.h"

namespace Makery
{
	struct GdiRenderer : Renderer
	{
		/// <summary>Win32 GDI graphics device context</summary>
		HDC hdc;

		/// <summary>Window height for converting from Point (Y zero at bottom) to Win32 GDI screen coordinate (Y zero at top)</summary>
		int height;

		/// <summary>Scale factor for converting from Point (Y zero at bottom) to Win32 GDI screen coordinate (Y zero at top)</summary>
		float scale = 1.0f;

		GdiRenderer(HDC windowDrawingContext, int windowHeight);

		virtual ~GdiRenderer();

		/// <summary>Moves the drawing pen to the specified position, do not draw</summary>
		bool moveTo(Point position);

		/// <summary>Draws a line from the current position to the specified position, and move the current position to the end point</summary>
		bool lineTo(Point position);

		/// <summary>Draws a circular arc (angles in radians, full circle at 2 pi)</summary>
		bool arcAt(Point centre,
			float radius, float startAngle, float endAngle);

		/// <summary>Draws an ellipse using the specified positions</summary>
		bool ellipse(Point bottomLeft, Point topRight);
	};
}
