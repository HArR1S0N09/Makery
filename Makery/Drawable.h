
#pragma once

#include "Renderer.h"

namespace Makery
{
	struct Drawable;

	/// <summary>Callback for Drawable</summary>
	typedef void(*DrawableCallback)(Drawable *thisObject, float scaleX, float scaleY);

	/// <summary>Interface for objects that can be drawn on the 2D surface of a computer screen</summary>
	struct Drawable
	{
		/// <summary>Callback for OnWindowDimensionsChanged event (optional)</summary>
		DrawableCallback callback;

		/// <summary>Indicates if this is the first time that the window dimensions change</summary>
		bool firstDimensionChange;

		/// <summary>Draws a shape on the 2D surface of a computer screen</summary>
		virtual bool draw(Renderer& renderer) = 0;

		/// <summary>Gets a copy of this drawable shape</summary>
		virtual Drawable* copy(void) = 0;

		virtual ~Drawable();

		/// <summary>De-allocate any object copied during construction or modification, set object to be empty</summary>
		virtual bool free(void) = 0;

		/// <summary>Handle the event when the window dimensions change</summary>
		virtual void OnWindowDimensionsChanged(float scaleX, float scaleY);
	};
}
