// Makery.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <cmath>

#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Diagram.h"
#include "Scaled.h"
#if TEST_RENDERER
#include "TestRenderer.h"
#endif
#include "GdiRenderer.h"

#include "Makery.h"

namespace Makery
{
	/// <summary>Indicates if this is the first time the diagram is drawn</summary>
	static bool firstTime = true;

	/// <summary>Margins for plot area</summary>
	static int margin = 30;

	/// <summary>Width of the window at the previous WM_PAINT event</summary>
	static int previousWidth = 0;

	/// <summary>Height of the window at the previous WM_PAINT event</summary>
	static int previousHeight = 0;

	/// <summary>Original dimensions of the window</summary>
	RECT originalDimensions;

	/// <summary>Dimensions of the window at the previous drawing rescale</summary>
	RECT previousDimensions;

	/// <summary>Centre for circle</summary>
	static Point circleCentre(187.5f, 333.5f);

	/// <summary>Circle</summary>
	static Circle circle(circleCentre, 93.75f);

	/// <summary>3 corners for the triangle</summary>
	static Point triangleCorners[3] =
	{
		{ 187.5f, 427.25f },
		{ 268.69f, 286.625f },
		{ 106.31f, 286.625f }
	};

	/// <summary>Triangle</summary>
	static Polygon triangle(triangleCorners, 3);

	/// <summary>Shapes to be used in the diagram</summary>
	static Drawable* shapes[2] =
	{
		&circle, &triangle
	};

	/// <summary>Diagram composed of a circle and a triangle inside the circle</summary>
	static Diagram diagram(shapes, 2);

	/// <summary>diagram scaled down by a third</summary>
	static Scaled scaledDiagram(0.3f, &diagram);

#if TEST_RENDERER
	/// <summary>Test renderer that displays the drawing commands on the text debug console</summary>
	static TestRenderer testRenderer;
#endif
}

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	Makery::diagram.add(&Makery::scaledDiagram);
#if TEST_RENDERER
	AllocConsole();
	FILE* newConsole;
	freopen_s(&newConsole, "CONOUT$", "w", stdout);
	freopen_s(&newConsole, "CONOUT$", "w", stderr);
	Makery::diagram.draw(testRenderer);
#endif

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MAKERY, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MAKERY));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAKERY));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MAKERY);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	Makery::firstTime = true;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_PAINT:
	{
		int windowWidth = 0;
		int windowHeight = 0;
		RECT windowDimensions;
		if (::GetClientRect(hWnd, &windowDimensions) != FALSE)
		{
			windowWidth = windowDimensions.right - windowDimensions.left;
			windowHeight = windowDimensions.bottom - windowDimensions.top;
		}

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		Makery::GdiRenderer gdiRenderer(hdc, windowHeight);
		if (Makery::firstTime)
		{
			Makery::originalDimensions = windowDimensions;
			Makery::previousDimensions = windowDimensions;
			Makery::firstTime = false;
			float x = (float) Makery::margin;
			float y = (float) Makery::margin;
			Makery::Point plotBottomLeft(x, y);
			Makery::Point plotTopRight(windowWidth - Makery::margin, windowHeight - Makery::margin);
			Makery::Rectangle plotArea(plotBottomLeft, plotTopRight);
			Makery::diagram.add(&plotArea);
			Makery::previousWidth = windowWidth;
			Makery::previousHeight = windowHeight;
		}
		else
		{
			if (windowWidth != Makery::previousWidth || windowHeight != Makery::previousHeight)
			{
				float previousWidth = Makery::previousDimensions.right - Makery::previousDimensions.left;
				float previousHeight = Makery::previousDimensions.bottom - Makery::previousDimensions.top;
				float scaleX = windowWidth / previousWidth;
				float scaleY = windowHeight / previousHeight;
				float deltaX = abs(1.0f - scaleX);
				float deltaY = abs(1.0f - scaleY);
				if (deltaX > 0.01f || deltaY > 0.01f)
				{
					float originalWidth = Makery::originalDimensions.right - Makery::originalDimensions.left;
					float originalHeight = Makery::originalDimensions.bottom - Makery::originalDimensions.top;
					scaleX = windowWidth / originalWidth;
					scaleY = windowHeight / originalHeight;
					Makery::diagram.OnWindowDimensionsChanged(scaleX, scaleY);
					Makery::previousDimensions = windowDimensions;
				}
			}
		}

		Makery::diagram.draw(gdiRenderer);
		EndPaint(hWnd, &ps);
		Makery::previousWidth = windowWidth;
		Makery::previousHeight = windowHeight;
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
