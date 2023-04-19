#include "3-calc.h"

/**
 * op_add - sums two numbers
 * @a: first number
 * @b: second number
 * Return: the sum of the two numbers as an integer
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - substruct @b for @a
 * @a: first number
 * @b: second number
 * Return: the result of @a minus @b as an integer
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers
 * @a: first number
 * @b: second number
 * Return: the multiplication of the two numbers as an integer
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two numbers
 * @a: first number
 * @b: second number
 * Return: the division of the two numbers as an integer
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - the rest of division of @a by @b
 * @a: first number
 * @b: second number
 * Return: the rest of the division of @a by @b as an integer
 */
int op_mod(int a, int b)
{
	return (a % b);
}
