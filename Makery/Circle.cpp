
#include "stdafx.h"

#include <cmath>

#include "Circle.h"

namespace Makery
{
	void Circle::WindowDimensionsChangedHandler(Drawable *thisObject,
		float scaleX, float scaleY)
	{
		Circle* me = (Circle*)thisObject;
		if (me->firstDimensionChange)
		{
			me->orignalCentre = me->centre;
			me->originalRadius = me->radius;
			me->firstDimensionChange = false;
		}

		me->centre.x = me->orignalCentre.x * scaleX;
		me->centre.y = me->orignalCentre.y * scaleY;
		me->isEllipse = abs(scaleX - scaleY) > 0.01;
		if (me->isEllipse)
		{
			me->bottomLeft.x = me->centre.x - (me->originalRadius * scaleX);
			me->bottomLeft.y = me->centre.y - (me->originalRadius * scaleY);
			me->topRight.x = me->centre.x + (me->originalRadius * scaleX);
			me->topRight.y = me->centre.y + (me->originalRadius * scaleY);
		}
		else
		{
			me->radius = me->originalRadius * scaleX;
		}
	}

	Circle::Circle(Point circleCentre, float circleRadius)
	{
		isEllipse = false;
		centre = circleCentre;
		radius = circleRadius;
		callback = WindowDimensionsChangedHandler;
	}

	Circle::Circle(const Circle* other)
	{
		isEllipse = other->isEllipse;
		if (isEllipse)
		{
			bottomLeft = other->bottomLeft;
			topRight = other->topRight;
		}

		centre = other->centre;
		radius = other->radius;
		callback = WindowDimensionsChangedHandler;
	}

	Drawable* Circle::copy(void)
	{
		Circle* newCircle = new Circle(this);
		return newCircle;
	}

	Circle::~Circle()
	{
		free();
	}

	bool Circle::free(void)
	{
		centre.x = 0.0f;
		centre.y = 0.0f;
		radius = 0.0f;
		callback = NULL;
		return true;
	}

	bool Circle::draw(Renderer& renderer)
	{
		if (isEllipse)
		{
			renderer.ellipse(bottomLeft, topRight);
		}
		else
		{
			renderer.circleAt(centre, radius);
		}

		return true;
	}
}