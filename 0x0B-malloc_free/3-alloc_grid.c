#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: number of rows
 * @height: number of columns
 *
 * Return: returns a pointer to a 2 dimensional array of integers
 * and NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid, h, w;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		*(grid + h) = (int *)malloc(sizeof(int) * width);

		if (*(grid + h) == NULL)
			return (NULL);
	}

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			*(*(grid + h) + w) = 0;
			w++;
		}
		h++;
	}

	return (grid);
}
