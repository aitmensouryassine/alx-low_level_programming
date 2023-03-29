#include "main.h"
/**
 * reverse_array - reverse the elements of an array
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 * Return: nothing.
 */
void reverse_array(int *a, int n)
{
	int i, tmp;

	for (i = 0; i < n; i++, n--)
	{
		tmp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = tmp;
	}
}
