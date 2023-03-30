#include "main.h"

/**
 * print_hex_2 - shows the hexadecimal content (2 chars)
 * of the buffer, 2 bytes at a time, separated by a space
 * @c: the buffer
 * @start: (integer) starting index
 * @end: (integer) ending index
*/
void print_hex_2(char *c, int start, int end)
{
	for (start; start < end; start += 2)
	{
		printf("%02x", c[start]);
		printf("%02x ", c[start + 1]);
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
*/
void print_printable_char(char *c, int start, int end)
{
	for (start; start < end; start++)
	{
		if (c[start] >= 32 && c[start] <= 126)
			_putchar(c[start]);
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
	int i, k = 0;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		print_hex_2(b, i, i + 10);
		print_printable_char(b, i, i + 10);
		_putchar('\n');
	}
}
