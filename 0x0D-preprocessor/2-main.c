#include "main.h"
#include <stdio.h>

/**
 * main - prints the name of the file it was compiled from,
 * followed by a new line.
 * Return: ALways 0
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
