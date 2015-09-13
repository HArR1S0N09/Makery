
#include "stdafx.h"

#include "Drawable.h"

namespace Makery
{
	Drawable::~Drawable()
	{
		// Allow derived classes to be destroyed through Drawable
	}

	void Drawable::OnWindowDimensionsChanged(float scaleX, float scaleY)
	{
		if (callback != NULL)
		{
			callback(this, scaleX, scaleY);
		}
	}
}