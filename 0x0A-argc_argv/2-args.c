#include "main.h"
#include <stdio.h>

/**
 * main - prints all arguments it receives
 * @argc: arguments count
 * @argv: arguments vector (array)
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	while (argc--)
	{
		printf("%s\n", *argv++);
	}
	printf("\n");

	return (0);
}
