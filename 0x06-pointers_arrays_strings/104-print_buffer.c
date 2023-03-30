#include "main.h"

/**
 * print_hex_2 - shows the hexadecimal content (2 chars)
 * of the buffer, 2 bytes at a time, separated by a space
 * @c: the buffer
 * @start: (integer) starting index
 * @end: (integer) ending index
 * @size: size of the buffer
 */
void print_hex_2(char *c, int start, int end, int size)
{
	int i;

	for (i = start; i < end; i++)
	{
		if (i >= size)
			printf("  ");
		else
			printf("%02x", c[i]);

		if ((i % 2) != 0 && i != 0)
			printf(" ");
	}
}

/**
 * print_hex_8 - shows the hexadecimal content (8chars)
 * of the position of the first char in the buffer
 * @pos: (integer) the position of the char in the buffer
 */
void print_hex_8(int pos)
{
	printf("%08x: ", pos);
}

/**
 * print_printable_char - prints only printable chars
 * @c: the buffer
 * @start: starting index
 * @end: ending index
 * @size: size of the buffer
 */
void print_printable_char(char *c, int start, int end, int size)
{
	int i;

	for (i = start; i < end; i++)
	{
		if (i >= size)
			break;

		if (c[i] >= 32 && c[i] <= 126)
			_putchar(c[i]);
		else
			_putchar('.');
	}
}

/**
 * print_buffer - prints a buffer
 * @b: the buffer
 * @size: size in bytes of the buffer to print
 * Return: nothing.
 */
void print_buffer(char *b, int size)
{
	if (size == 0)
	{
		printf("\n");
	}
	else
	{
		int i;

		for (i = 0; i < size; i += 10)
		{
			printf("%08x: ", i);
			print_hex_2(b, i, i + 10, size);
			print_printable_char(b, i, i + 10, size);

			if (i >= size)
				continue;

			_putchar('\n');
		}
	}
}
