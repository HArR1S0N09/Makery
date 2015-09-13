
#pragma once

namespace Makery
{
	/// <summary>A position in 2D drawing space for dots, line end points, curve anchors...</summary>
	struct Point
	{
		/// <summary>Horizontal coordinate, zero on the left, increasing from left to right</summary>
		float x;

		/// <summary>Vertical coordinate, zero at the bottom, increasing from bottom to top</summary>
		float y;

		/// <summary>Initialises a new instance of a Point</summary>
		Point();

		/// <summary>Initialises a new instance of a Point</summary>
		Point(float pointX, float pointY);
	};
}