#include "slide_line.h"
/**
 * slide_left - Slide to the left
 * @line: Pointer to an array of integers
 * @size: Number of elements in line array;
 * Return: 1 yay, 0 nay
 */
int slide_left(int *line, size_t size)
{
	int x = 0, y = 0;
	size_t count = 0, i = 0;

	for (; i < size; i++)
	{
		if (line[i] != 0 && x == 0)
			x = line[i];
		else if (line[i] != 0 && x != 0)
			y = line[i];
		if (x != 0 && y != 0)
		{
			if (x == y)
			{
				line[count++] = x + y;
				x = 0;
				y = 0;
			}
			else
			{
				line[count++] = x;
				x = y;
				y = 0;
				if (i == size - 1)
					line[count++] = x;
			}
		}
		else if (x != y && i == size - 1)
			line[count++] = x;
	}
	for (i = count; i < size; i++)
		line[i] = 0;
	return (1);
}
/**
 * slide_right - Slide to the right
 * @line: Pointer to an array of integers
 * @size: Number of elements in line array;
 * Return: 1 yay, 0 nay
 */
int slide_right(int *line, size_t size)
{
	int x = 0, y = 0;
	size_t count = size - 1, i = size - 1;

	for (; i < size; i--)
	{
		if (line[i] != 0 && x == 0)
			x = line[i];
		else if (line[i] != 0 && x != 0)
			y = line[i];
		if (x != 0 && y != 0)
		{
			if (x == y)
			{
				line[count--] = x + y;
				x = 0;
				y = 0;
			}
			else
			{
				line[count--] = x;
				x = y;
				y = 0;
				if (i == 0)
					line[count--] = x;
			}
		}
		else if (x != y && i == 0)
			line[count--] = x;
	}
	for (i = 0; i < count + 1; i++)
		line[i] = 0;
	return (1);
}
/**
 * slide_line - Slides & merges integers on a horizontal line either way.
 * @line: Pointer to an array of integers
 * @size: Number of elements in line array;
 * @direction: Direction to slide integers on horizontal line.
 * Return: 1 yay, 0 nay
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	return (slide_left(line, size));
}
