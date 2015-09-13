<?xml version="1.0"?><doc>
<members>
<member name="T:Makery.Point" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\point.h" line="6">
<summary>A position in 2D drawing space for dots, line end points, curve anchors...</summary>
</member>
<member name="F:Makery.Point.x" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\point.h" line="9">
<summary>Horizontal coordinate, zero on the left, increasing from left to right</summary>
</member>
<member name="F:Makery.Point.y" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\point.h" line="12">
<summary>Vertical coordinate, zero at the bottom, increasing from bottom to top</summary>
</member>
<member name="M:Makery.Point.#ctor" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\point.h" line="15">
<summary>Initialises a new instance of a Point</summary>
</member>
<member name="M:Makery.Point.#ctor(System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\point.h" line="18">
<summary>Initialises a new instance of a Point</summary>
</member>
<member name="T:Makery.Renderer" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="11">
<summary>Pen used to draw simple strokes on the 2D space of a computer display</summary>
</member>
<member name="M:Makery.Renderer.moveTo(Makery.Point)" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="14">
<summary>Moves the drawing pen to the specified position, do not draw</summary>
</member>
<member name="M:Makery.Renderer.lineTo(Makery.Point)" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="17">
<summary>Draws a line from the current position to the specified position, and move the current position to the end point</summary>
</member>
<member name="M:Makery.Renderer.arcAt(Makery.Point,System.Single,System.Single,System.Single)" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="20">
<summary>Draws a circular arc (angles in radians, full circle at 2 pi)</summary>
</member>
<member name="M:Makery.Renderer.ellipse(Makery.Point,Makery.Point)" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="23">
<summary>Draws an ellipse using the specified positions</summary>
</member>
<member name="M:Makery.Renderer.circleAt(Makery.Point,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="26">
<summary>Draws a circle at the specified position and with the given radius</summary>
</member>
<member name="M:Makery.Renderer.rectangleAt(Makery.Point,Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\renderer.h" line="29">
<summary>Draws a rectangle between the specified positions</summary>
</member>
<member name="F:Makery.GdiRenderer.hdc" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="9">
<summary>Win32 GDI graphics device context</summary>
</member>
<member name="F:Makery.GdiRenderer.height" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="12">
<summary>Window height for converting from Point (Y zero at bottom) to Win32 GDI screen coordinate (Y zero at top)</summary>
</member>
<member name="F:Makery.GdiRenderer.scale" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="15">
<summary>Scale factor for converting from Point (Y zero at bottom) to Win32 GDI screen coordinate (Y zero at top)</summary>
</member>
<member name="M:Makery.GdiRenderer.moveTo(Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="22">
<summary>Moves the drawing pen to the specified position, do not draw</summary>
</member>
<member name="M:Makery.GdiRenderer.lineTo(Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="25">
<summary>Draws a line from the current position to the specified position, and move the current position to the end point</summary>
</member>
<member name="M:Makery.GdiRenderer.arcAt(Makery.Point,System.Single,System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="28">
<summary>Draws a circular arc (angles in radians, full circle at 2 pi)</summary>
</member>
<member name="M:Makery.GdiRenderer.ellipse(Makery.Point,Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\gdirenderer.h" line="32">
<summary>Draws an ellipse using the specified positions</summary>
</member>
</members>
</doc>