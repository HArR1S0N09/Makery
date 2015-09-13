
#include "stdafx.h"

#include "GdiRenderer.h"

namespace Makery
{
	GdiRenderer::GdiRenderer(HDC windowDrawingContext, int windowHeight)
	{
		hdc = windowDrawingContext;
		height = windowHeight;
	}


	GdiRenderer::~GdiRenderer()
	{
	}

	bool GdiRenderer::moveTo(Point position)
	{
		int x = (int)(position.x * scale);
		int y = (int)(height - (position.y * scale));
		BOOL result = ::MoveToEx(hdc, x, y, NULL);
		return result != FALSE;
	}

	bool GdiRenderer::lineTo(Point position)
	{
		int x = (int)(position.x * scale);
		int y = (int)(height - (position.y * scale));
		BOOL result = ::LineTo(hdc, x, y);
		return result != FALSE;
	}

	bool GdiRenderer::arcAt(Point centre,
		float radius, float startAngle, float endAngle)
	{
		int centreX = (int)(centre.x * scale);
		int centreY = (int)(height - (centre.y * scale));
		float startDegrees = startAngle * 360.0f / twoPi;
		float endDegrees = endAngle * 360.0f / twoPi;
		int scaledRadius = (int)(radius * scale);
		int startX = centreX + scaledRadius;
		::MoveToEx(hdc, startX, centreY, NULL);
		BOOL result = ::AngleArc(hdc, centreX, centreY, scaledRadius, startDegrees, endDegrees);
		return result != FALSE;
	}

	bool GdiRenderer::ellipse(Point bottomLeft, Point topRight)
	{
		int topY = (int)(height - topRight.y);
		int bottomY = (int)(height - bottomLeft.y);
		BOOL result = ::Ellipse(hdc, (int)bottomLeft.x,
			topY, (int)topRight.x, bottomY);
		return result != FALSE;
	}
}