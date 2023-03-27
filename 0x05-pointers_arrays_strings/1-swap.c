#include "main.h"

/**
 * swap_int - swap the value of two integers
 * @a: the first integer to swap its value
 * @b: the second integer to swap its value
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
