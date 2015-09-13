#pragma once

#include "Drawable.h"

namespace Makery
{
	/// <summary>Shape that can be scaled</summary>
	struct Scaled : Drawable
	{
		/// <summary>Scaling factor</summary>
		float scale;

		/// <summary>Shape to be scaled</summary>
		Drawable* subject;

		Scaled(float scaleFactor, Drawable* shapeToBeScaled);

		Scaled(const Scaled* other);

		Drawable* copy(void);

		virtual ~Scaled();

		bool free(void);

		/// <summary>Draws a scaled shape on the 2D surface of a computer screen</summary>
		bool draw(Renderer& renderer);

		void OnWindowDimensionsChanged(float scaleX, float scaleY);
	};
}
