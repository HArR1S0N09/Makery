
#include "stdafx.h"

#include <iostream>

#include "TestRenderer.h"

namespace Makery
{
	bool TestRenderer::moveTo(Point position)
	{
		*outputStream << L"// moveTo(" <<
			L"position.x, position.y)" << endl;
		*outputStream << L"moveTo(" <<
			position.x << L", " << position.y << L")" << endl;
		return true;
	}

	bool TestRenderer::lineTo(Point position)
	{
		*outputStream << L"// lineTo(" <<
			L"position.x, position.y)" << endl;
		*outputStream << L"lineTo(" <<
			position.x << L", " << position.y << L")" << endl;
		return true;
	}

	bool TestRenderer::arcAt(Point centre,
		float radius, float startAngle, float endAngle)
	{
		*outputStream << L"// arcAt(" <<
			L"centre.x, centre.y, radius, startAngle, endAngle)" << endl;
		*outputStream << L"arcAt(" <<
			centre.x << L", " << centre.y << L", " <<
			radius << L", " <<
			startAngle << L", " << endAngle <<
			L")" << endl;
		return true;
	}

	bool TestRenderer::ellipse(Point bottomLeft, Point topRight)
	{
		*outputStream << L"// ellipse(" <<
			L"bottomLeft.x, bottomLeft.y, topRight.x, topRight.y" << endl;
		*outputStream << L"ellipse(" <<
			bottomLeft.x << L", " << bottomLeft.y << L", " <<
			topRight.x << L", " << topRight.y <<
			L")" << endl;
		return true;
	}
}