
#pragma once

#include "Drawable.h"

namespace Makery
{
	/// <summary>Size of elements array in a diagram at the first initialisation</summary>
	const size_t elementSize = 2;

	/// <summary>Set of shapes to be drawn on a 2D computer screen</summary>
	struct Diagram : Drawable
	{
		/// <summary>Elements (shapes, other diagrams) in the diagram</summary>
		Drawable** elements;

		/// <summary>Number of elements (shapes, other diagrams) in the diagram</summary>
		size_t elementCount = 0;

		/// <summary>Index to the last element added to this diagram</summary>
		size_t lastElement = 0;

		/// <summary>Initialises a new instance of a Diagram</summary>
		Diagram(Drawable* diagramElements[], size_t diagramElementCount);

		Diagram(const Diagram* other);

		Drawable* copy(void);

		virtual ~Diagram();

		bool free(void);

		/// <summary>Draws all the elements (shapes, other diagrams) of the diagram</summary>
		bool draw(Renderer& renderer);

		/// <summary>Adds a new element to the diagram</summary>
		bool add(Drawable* newElement);

		/// <summary>Rescale the entire diagram</summary>
		void OnWindowDimensionsChanged(float scaleX, float scaleY);
	};
}
