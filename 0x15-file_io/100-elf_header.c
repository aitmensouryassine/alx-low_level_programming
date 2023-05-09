#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * check_elf - check if a file is an elf file or not
 * @header: the elf header
 */
void check_elf(Elf64_Ehdr *header)
{
	if (header->e_type != 0x7f &&
	    header->e_ident[1] != 'E' &&
	    header->e_ident[2] != 'L' &&
	    header->e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: The file is not an ELF file\n");
		exit(98);
	}
}

/**
 * error - print error and exit with code
 * @code: the error code
 * @format: the format string
 * @str: a string
 */
void error(int code, char *format, char *str)
{
	dprintf(STDERR_FILENO, format, str);
	exit(code);
}

/**
 * magic - prints magic
 * @header: the elf header
 */
void magic(Elf64_Ehdr *header)
{
	int i = 0;

	printf("ELF Header:\n  Magic:  ");

	while (i < 16)
	{
		printf(" %02x", header->e_ident[i]);
		i++;
	}
	printf("\n");
}
/**
 * class - prints the architecture for the binary
 * @header: the elf header
 */
void class(Elf64_Ehdr *header)
{
	printf("  Class:                             ");

	if (header->e_ident[4] == ELFCLASSNONE)
		printf("NONE\n");

	if (header->e_ident[4] == ELFCLASS32)
		printf("ELF32\n");

	if (header->e_ident[4] == ELFCLASS64)
		printf("ELF64\n");
}
/**
 * main - displays the information contained in the ELF header at
 * the start of an ELF file.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 * 98 if the file is not an ELF file
 */
int main(int argc, char **argv)
{
	char *elf;
	int fd, rd;
	Elf64_Ehdr *header;

	if (argc != 2)
		error(98, "Usage: %s elf_file\n", argv[0]);

	header = malloc(sizeof(Elf64_Ehdr));

	elf = argv[1];

	fd = open(elf, O_RDONLY);
	rd = read(fd, header, sizeof(header));
	if (fd < 0 || rd < 0 || !header)
		error(98, "Error: Can't open/read elf file %s\n", elf);

	check_elf(header);
	magic(header);
	class(header);

	return (0);
}
