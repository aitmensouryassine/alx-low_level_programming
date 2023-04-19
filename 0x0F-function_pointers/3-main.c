#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"

/**
 * main - simple calculator
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98, 99 or 100 on failure
 */

int main(int argc, char **argv)
{
	int a, b;
	int (*operator)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]), b = atoi(argv[3]);
	if ((*argv[2] == '/' || *argv[2] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	operator= get_op_func(argv[2]);

	if (!operator)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", operator(a, b));

	return (EXIT_SUCCESS);
}
