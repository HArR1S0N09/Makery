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
<member name="T:Makery.TestRenderer" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\testrenderer.h" line="12">
<summary>Exposes the internals of Renderer by printing out the graphics primitive to a debug stream instead of executing them</summary>
</member>
<member name="F:Makery.TestRenderer.outputStream" decl="false" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\testrenderer.h" line="15">
<summary>Destination for test messages: standard logging (debug) stream</summary>
</member>
<member name="M:Makery.TestRenderer.moveTo(Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\testrenderer.h" line="18">
<summary>Moves the drawing pen to the specified position, do not draw</summary>
</member>
<member name="M:Makery.TestRenderer.lineTo(Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\testrenderer.h" line="21">
<summary>Draws a line from the current position to the specified position, and move the current position to the end point</summary>
</member>
<member name="M:Makery.TestRenderer.arcAt(Makery.Point,System.Single,System.Single,System.Single)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\testrenderer.h" line="24">
<summary>Draws a circular arc (angles in radians, full circle at 2 pi)</summary>
</member>
<member name="M:Makery.TestRenderer.ellipse(Makery.Point,Makery.Point)" decl="true" source="c:\users\francois\documents\visual studio 2015\projects\makery\makery\testrenderer.h" line="28">
<summary>Draws an ellipse using the specified positions</summary>
</member>
</members>
</doc>