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
	int index;

	for (index = 0; index < 10; index++)
	{
		if ((index + byte) >= size)
			printf("  ");

		else
			printf("%02x", b[index + byte]);

		if ((index % 2) != 0 && index != 0)
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
	int index;

	for (index = 0; index < 10; index++)
	{
		if ((index + byte) >= size)
			break;

		else if (b[index + byte] >= 31 && b[index + byte] <= 126)
			printf("%c", b[index + byte]);

		else
			printf(".");
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
	int byte;

	for (byte = 0; byte < size; byte += 10)
	{
		print_hex_8(byte);
		print_hex_2(b, byte, size);
		print_printable_char(b, byte, size);

		if (byte >= size)
			continue;

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
