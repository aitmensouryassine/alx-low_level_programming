#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints its own opcodes
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 or 2 on failure
 */

int main(int argc, char **argv)
{
	int number_of_bytes, i;
	char *m = (char *)main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	number_of_bytes = atoi(argv[1]);

	if (number_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < number_of_bytes - 1; i++)
		printf("%02hhx ", m[i]);
	printf("%02hhx\n", m[number_of_bytes - 1]);

	return (EXIT_SUCCESS);
}
