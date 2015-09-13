
#include "stdafx.h"

#include "Rectangle.h"

namespace Makery
{
	void Rectangle::WindowDimensionsChangedHandler(Drawable *thisObject,
		float scaleX, float scaleY)
	{
		Rectangle* me = (Rectangle*)thisObject;
		if (me->firstDimensionChange)
		{
			me->originalBottomLeft = me->bottomLeft;
			me->originalTopRight = me->topRight;
			me->firstDimensionChange = false;
		}

		me->bottomLeft.x = me->originalBottomLeft.x * scaleX;
		me->bottomLeft.y = me->originalBottomLeft.y * scaleY;
		me->topRight.x = me->originalTopRight.x * scaleX;
		me->topRight.y = me->originalTopRight.y * scaleY;
	}

	Rectangle::Rectangle(Point bottomLeftCorner, Point topRightCorner)
	{
		firstDimensionChange = true;
		bottomLeft = bottomLeftCorner;
		topRight = topRightCorner;
		callback = WindowDimensionsChangedHandler;
	}

	Rectangle::Rectangle(const Rectangle* other)
	{
		firstDimensionChange = true;
		bottomLeft = other->bottomLeft;
		topRight = other->topRight;
		callback = WindowDimensionsChangedHandler;
	}

	Drawable* Rectangle::copy(void)
	{
		Rectangle* newRectangle = new Rectangle(this);
		return newRectangle;
	}

	Rectangle::~Rectangle()
	{
		free();
	}

	bool Rectangle::free()
	{
		callback = NULL;
		bottomLeft.x = 0.0f;
		bottomLeft.y = 0.0f;
		topRight.x = 0.0f;
		topRight.y = 0.0f;
		return true;
	}

	bool Rectangle::draw(Renderer& renderer)
	{
		return renderer.rectangleAt(bottomLeft, topRight);
	}
}