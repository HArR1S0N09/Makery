
#include "stdafx.h"

#include "Scaled.h"
#include "ScaledRenderer.h"

namespace Makery
{
	Scaled::Scaled(float scaleFactor, Drawable* shapeToBeScaled)
	{
		scale = scaleFactor;
		subject = shapeToBeScaled->copy();
		callback = NULL;
	}

	Scaled::Scaled(const Scaled* other)
	{
		scale = other->scale;
		subject = other->subject->copy();
		callback = NULL;
	}

	Drawable* Scaled::copy(void)
	{
		Scaled* newScaled = new Scaled(this);
		return newScaled;
	}

	Scaled::~Scaled()
	{
		free();
	}

	bool Scaled::free(void)
	{
		callback = NULL;
		if (subject == NULL)
		{
			return true;
		}

		delete subject;
		subject = NULL;
		scale = 0.0f;
		return true;
	}

	bool Scaled::draw(Renderer& renderer)
	{
		ScaledRenderer scaledRenderer(&renderer, scale);
		return subject->draw(scaledRenderer);
	}

	void Scaled::OnWindowDimensionsChanged(float scaleX, float scaleY)
	{
		subject->OnWindowDimensionsChanged(scaleX, scaleY);
	}
}
