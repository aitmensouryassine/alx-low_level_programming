#include "main.h"

/**
 * print_hex_2 - shows the hexadecimal content (2 chars)
 * of the buffer, 2 bytes at a time, separated by a space
 * @b: the buffer
 * @byte: (integer) index
 * @size: size of the buffer
 */
void print_hex_2(char *b, int byte, int size)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if ((i + byte) >= size)
			printf("  ");
		else
			printf("%02x", b[i + byte]);

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
 * @b: the buffer
 * @byte: index
 * @size: size of the buffer
 */
void print_printable_char(char *b, int byte, int size)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if ((i + byte) >= size)
			break;

		else if (b[i + byte] >= 31 && b[i + byte] <= 126)
			_putchar(b[i + byte]);
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
	if (size <= 0)
	{
		printf("\n");
	}
	else
	{
		int byte;

		for (byte = 0; byte < size; byte += 10)
		{
			printf("%08x: ", byte);
			print_hex_2(b, byte, size);
			print_printable_char(b, byte, size);

			if (byte >= size)
				continue;

			_putchar('\n');
		}
	}
}
