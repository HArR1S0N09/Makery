
#include "stdafx.h"

#include "Diagram.h"

namespace Makery
{
	Diagram::Diagram(Drawable* diagramElements[], size_t diagramElementCount)
	{
		size_t arraySize = elementSize;
		if (diagramElementCount > arraySize)
		{
			arraySize = diagramElementCount + elementSize;
		}

		elements = new Drawable*[arraySize];
		size_t element = 0;
		while (element < diagramElementCount)
		{
			elements[element] = diagramElements[element]->copy();
			element++;
		}

		elementCount = arraySize;
		lastElement = diagramElementCount;
		callback = NULL;
	}

	Diagram::Diagram(const Diagram* other)
	{
		elements = new Drawable*[other->elementCount];
		size_t element = 0;
		while (element < other->lastElement)
		{
			elements[element] = other->elements[element]->copy();
			element++;
		}

		elementCount = other->elementCount;
		lastElement = other->lastElement;
		callback = NULL;
	}

	Drawable* Diagram::copy(void)
	{
		Diagram* newDiagram = new Diagram(this);
		return newDiagram;
	}

	Diagram::~Diagram()
	{
		free();
	}

	bool Diagram::free(void)
	{
		callback = NULL;
		if (elements == NULL)
		{
			return true;
		}

		size_t element = 0;
		while (element < lastElement)
		{
			delete elements[element];
			elements[element] = NULL;
			element++;
		}

		delete[] elements;
		elements = NULL;
		lastElement = 0;
		elementCount = 0;
		return true;
	}

	bool Diagram::draw(Renderer& renderer)
	{
		if (elementCount == 0 || elements == NULL || lastElement == 0)
		{
			return true;
		}

		size_t element = 0;
		while (element < lastElement)
		{
			elements[element]->draw(renderer);
			element++;
		}

		return true;
	}

	bool Diagram::add(Drawable* newElement)
	{
		if (elementCount == 0 || elements == NULL)
		{
			elements = new Drawable*[elementSize];
			elementCount = elementSize;
			lastElement = 0;
		}
		else if (lastElement >= elementCount)
		{
			size_t newElementCount = elementCount + elementSize;
			Drawable** oldElements = elements;
			Drawable** newElements = new Drawable*[newElementCount];
			size_t element = 0;
			while (element < elementCount)
			{
				newElements[element] = oldElements[element];
				element++;
			}

			element = 0;
			while (element < elementCount)
			{
				oldElements[element] = NULL;
				element++;
			}

			elements = newElements;
			elementCount = newElementCount;
			delete[] oldElements;
		}

		elements[lastElement] = newElement->copy();
		lastElement++;
		return true;
	}

	void Diagram::OnWindowDimensionsChanged(float scaleX, float scaleY)
	{
		if (elementCount == 0 || elements == NULL || lastElement == 0)
		{
			return;
		}

		size_t element = 0;
		while (element < lastElement)
		{
			elements[element]->OnWindowDimensionsChanged(scaleX, scaleY);
			element++;
		}
	}
}