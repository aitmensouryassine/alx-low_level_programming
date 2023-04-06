#include "main.h"
#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: arguments count
 * @argv: arguments vector (array)
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", *argv);

	return (0);
}
