#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: the 2D grid (array)
 * @height: the height ogf the grid (or rows of the array)
 */
void free_grid(int **grid, int height)
{
	int i;

	free(grid);
	for (i = 0; i < height; i++)
	{
		free(*(grid + i));
	}
}
