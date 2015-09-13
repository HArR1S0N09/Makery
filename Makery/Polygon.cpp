
#include "stdafx.h"

#include "Polygon.h"

namespace Makery
{
	void Polygon::WindowDimensionsChangedHandler(Drawable *thisObject,
		float scaleX, float scaleY)
	{
		Polygon* me = (Polygon*)thisObject;
		if (me->firstDimensionChange)
		{
			me->originalCorners = new Point[me->cornerCount];
			size_t corner = 0;
			while (corner < me->cornerCount)
			{
				me->originalCorners[corner] = me->corners[corner];
				corner++;
			}

			me->firstDimensionChange = false;
		}

		size_t corner = 0;
		while (corner < me->cornerCount)
		{
			me->corners[corner].x = me->originalCorners[corner].x * scaleX;
			me->corners[corner].y = me->originalCorners[corner].y * scaleY;
			corner++;
		}
	}

	Polygon::Polygon(Point* polygonCorners, size_t polygonCornerCount)
	{
		firstDimensionChange = true;
		corners = new Point[polygonCornerCount];
		size_t corner = 0;
		while (corner < polygonCornerCount)
		{
			corners[corner] = polygonCorners[corner];
			corner++;
		}

		cornerCount = polygonCornerCount;
		callback = WindowDimensionsChangedHandler;
		originalCorners = NULL;
	}

	Polygon::Polygon(const Polygon* other)
	{
		firstDimensionChange = true;
		corners = new Point[other->cornerCount];
		size_t corner = 0;
		while (corner < other->cornerCount)
		{
			corners[corner] = other->corners[corner];
			corner++;
		}

		cornerCount = other->cornerCount;
		if (other->originalCorners != NULL)
		{
			originalCorners = new Point[cornerCount];
			size_t corner = 0;
			while (corner < cornerCount)
			{
				originalCorners[corner] = other->originalCorners[corner];
				corner++;
			}

			firstDimensionChange = false;
		}

		callback = WindowDimensionsChangedHandler;
	}

	Drawable* Polygon::copy(void)
	{
		Polygon* newPolygon = new Polygon(this);
		return newPolygon;
	}

	Polygon::~Polygon()
	{
		free();
	}

	bool Polygon::free(void)
	{
		callback = NULL;
		if (corners != NULL)
		{
			size_t corner = 0;
			while (corner < cornerCount)
			{
				corners[corner].x = 0.0f;
				corners[corner].y = 0.0f;
				corner++;
			}

			delete[] corners;
			corners = NULL;
		}

		if (originalCorners != NULL)
		{
			size_t corner = 0;
			while (corner < cornerCount)
			{
				originalCorners[corner].x = 0.0f;
				originalCorners[corner].y = 0.0f;
				corner++;
			}

			delete[] originalCorners;
			originalCorners = NULL;
		}

		cornerCount = 0;
		return true;
	}

	bool Polygon::draw(Renderer& renderer)
	{
		if (cornerCount == 0 || corners == NULL)
		{
			return true;
		}

		Point last = corners[cornerCount - 1];
		renderer.moveTo(last);
		size_t corner = 0;
		while (corner < cornerCount)
		{
			Point position = corners[corner];
			renderer.lineTo(position);
			corner++;
		}

		return true;
	}
}