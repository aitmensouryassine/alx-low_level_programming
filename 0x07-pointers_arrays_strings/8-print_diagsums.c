#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: the matrix (2d array)
 * @size: size of the matrix
*/
void print_diagsums(int *a, int size)
{
	int i, sum = 0, sum1 = 0;

	for (i = 0; i < size * size; i += (size + 1))
		sum += *(a + i);

	for (i = (size - 1); i < (size * size) - 1; i += (size - 1))
		sum1 += *(a + i);

	printf("%d, %d\n", sum, sum1);
}
