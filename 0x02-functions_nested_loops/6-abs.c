#include "main.h"
/**
 * _abs - computes the absolute value of an integer
 * @n: integer to compute its absolute value
 * Return: Integer that is the absolute value of the given integer
 */
int _abs(int n)
{
	int sign = (n == 0) ? 0 : (n > 0) ? 1 : -1;

	return (n * sign);
}
