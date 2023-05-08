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
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_file\n", argv[0]);
		exit(96);
	}

	header = malloc(sizeof(Elf64_Ehdr));

	elf = argv[1];

	fd = open(elf, O_RDONLY);
	rd = read(fd, header, sizeof(header));
	if (fd < 0 || rd < 0 || !header)
	{
		dprintf(STDERR_FILENO, "Error: Can't open/read elf file %s\n", elf);
		exit(97);
	}

	check_elf(header);

	return (0);
}
