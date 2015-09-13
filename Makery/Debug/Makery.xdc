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
<member name="D:Makery.DrawableCallback" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="10">
<summary>Callback for Drawable</summary>
</member>
<member name="T:Makery.Drawable" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="13">
<summary>Interface for objects that can be drawn on the 2D surface of a computer screen</summary>
</member>
<member name="F:Makery.Drawable.callback" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="16">
<summary>Callback for OnWindowDimensionsChanged event (optional)</summary>
</member>
<member name="F:Makery.Drawable.firstDimensionChange" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="19">
<summary>Indicates if this is the first time that the window dimensions change</summary>
</member>
<member name="M:Makery.Drawable.draw(Makery.Renderer*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="22">
<summary>Draws a shape on the 2D surface of a computer screen</summary>
</member>
<member name="M:Makery.Drawable.copy" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="25">
<summary>Gets a copy of this drawable shape</summary>
</member>
<member name="M:Makery.Drawable.free" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="30">
<summary>De-allocate any object copied during construction or modification, set object to be empty</summary>
</member>
<member name="M:Makery.Drawable.OnWindowDimensionsChanged(System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\drawable.h" line="33">
<summary>Handle the event when the window dimensions change</summary>
</member>
<member name="M:Makery.Rectangle.draw(Makery.Renderer*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\rectangle.h" line="27">
<summary>Draws the polygon using the array of corners</summary>
</member>
<member name="T:Makery.Circle" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\circle.h" line="9">
<summary>Shape made of a circle at specified position and with given radius</summary>
</member>
<member name="M:Makery.Circle.WindowDimensionsChangedHandler(Makery.Drawable*,System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\circle.h" line="12">
<summary>Rescale the circle when the window resizes</summary>
</member>
<member name="F:Makery.Circle.centre" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\circle.h" line="16">
<summary>Position for the centre of the circle</summary>
</member>
<member name="F:Makery.Circle.radius" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\circle.h" line="19">
<summary>Radius for the circle</summary>
</member>
<member name="M:Makery.Circle.#ctor(Makery.Point,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\circle.h" line="32">
<summary>Initialises a new instance of a Circle</summary>
</member>
<member name="M:Makery.Circle.draw(Makery.Renderer*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\circle.h" line="43">
<summary>Draws the circle at the specified position and with the given radius</summary>
</member>
<member name="T:Makery.Polygon" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="9">
<summary>Shape made of closed multi-line segments (no gaps, first point is different from the last point)</summary>
</member>
<member name="M:Makery.Polygon.WindowDimensionsChangedHandler(Makery.Drawable*,System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="12">
<summary>Rescale the polygon when the window resizes</summary>
</member>
<member name="F:Makery.Polygon.corners" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="16">
<summary>Array of positions for all the corners of the polygon</summary>
</member>
<member name="F:Makery.Polygon.cornerCount" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="19">
<summary>Number of positions for all the corners of the polygon</summary>
</member>
<member name="F:Makery.Polygon.originalCorners" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="22">
<summary>Original corners, before any window resize happened</summary>
</member>
<member name="M:Makery.Polygon.#ctor(Makery.Point*,System.UInt32)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="25">
<summary>Initialises a new instance of a Polygon</summary>
</member>
<member name="M:Makery.Polygon.draw(Makery.Renderer*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\polygon.h" line="36">
<summary>Draws the polygon using the array of corners</summary>
</member>
<member name="T:Makery.Diagram" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="11">
<summary>Set of shapes to be drawn on a 2D computer screen</summary>
</member>
<member name="F:Makery.Diagram.elements" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="14">
<summary>Elements (shapes, other diagrams) in the diagram</summary>
</member>
<member name="F:Makery.Diagram.elementCount" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="17">
<summary>Number of elements (shapes, other diagrams) in the diagram</summary>
</member>
<member name="F:Makery.Diagram.lastElement" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="20">
<summary>Index to the last element added to this diagram</summary>
</member>
<member name="M:Makery.Diagram.#ctor(Makery.Drawable**,System.UInt32)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="23">
<summary>Initialises a new instance of a Diagram</summary>
</member>
<member name="M:Makery.Diagram.draw(Makery.Renderer*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="34">
<summary>Draws all the elements (shapes, other diagrams) of the diagram</summary>
</member>
<member name="M:Makery.Diagram.add(Makery.Drawable*)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="37">
<summary>Adds a new element to the diagram</summary>
</member>
<member name="M:Makery.Diagram.OnWindowDimensionsChanged(System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\diagram.h" line="40">
<summary>Rescale the entire diagram</summary>
</member>
<member name="T:Makery.Scaled" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\scaled.h" line="7">
<summary>Shape that can be scaled</summary>
</member>
<member name="F:Makery.Scaled.scale" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\scaled.h" line="10">
<summary>Scaling factor</summary>
</member>
<member name="F:Makery.Scaled.subject" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\scaled.h" line="13">
<summary>Shape to be scaled</summary>
</member>
<member name="M:Makery.Scaled.draw(Makery.Renderer*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\scaled.h" line="26">
<summary>Draws a scaled shape on the 2D surface of a computer screen</summary>
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
<member name="F:Makery.originalDimensions" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\makery.cpp" line="34">
<summary>Original dimensions of the window</summary>
</member>
<member name="F:Makery.previousDimensions" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\makery.cpp" line="37">
<summary>Dimensions of the window at the previous drawing rescale</summary>
</member>
</members>
</doc>