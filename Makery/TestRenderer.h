
#pragma once

#include <iostream>

#include "Renderer.h"

using namespace std;

namespace Makery
{
	/// <summary>Exposes the internals of Renderer by printing out the graphics primitive to a debug stream instead of executing them</summary>
	struct TestRenderer : Renderer
	{
		/// <summary>Destination for test messages: standard logging (debug) stream</summary>
		basic_ostream<wchar_t>* outputStream = &wclog;

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