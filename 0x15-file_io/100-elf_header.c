#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * check_elf - check if a file is an elf file or not
 * @header: the elf header
 */
void check_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[0] != 0x7f &&
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
 * data - print the data encoding of the processor-specific data
 * @header: the elf header
 */
void data(Elf64_Ehdr *header)
{
	printf("  Data:                              ");

	if (header->e_ident[5] == ELFDATANONE)
		printf("Unknown data format\n");

	if (header->e_ident[5] == ELFDATA2LSB)
		printf("2's complement, little-endian\n");

	if (header->e_ident[5] == ELFDATA2MSB)
		printf("2's complement, big-endian\n");
}
/**
 * version - print the version number of the ELF specification
 * @header: the elf header
 */
void version(Elf64_Ehdr *header)
{
	printf("  Version:                           ");

	if (header->e_ident[6] == EV_NONE)
		printf("Invalid version\n");

	if (header->e_ident[6] == EV_CURRENT)
		printf("%d (current)\n", EV_CURRENT);
}
/**
 * osabi - prints the operating system and ABI
 * @header: the elf header
 */
void osabi(Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");

	if (header->e_ident[7] == ELFOSABI_NONE ||
	    header->e_ident[7] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");

	if (header->e_ident[7] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");

	if (header->e_ident[7] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");

	if (header->e_ident[7] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");

	if (header->e_ident[7] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");

	if (header->e_ident[7] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");

	if (header->e_ident[7] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");

	if (header->e_ident[7] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");

	if (header->e_ident[7] == ELFOSABI_ARM)
		printf("UNIX - ARM\n");

	if (header->e_ident[7] == ELFOSABI_STANDALONE)
		printf("Stand-alone (embedded)\n");
}
/**
 * abiversion - prints the version of the ABI
 * @header: the elf header
 */
void abiversion(Elf64_Ehdr *header)
{
	printf("  ABI Version:                       %d\n", header->e_ident[8]);
}
/**
 * type - prints the object file type
 * @header: the elf header
 */
void type(Elf64_Ehdr *header)
{
	unsigned int e_type = header->e_type;

	printf("  Type:                              ");

	if (e_type == ET_NONE)
	{
		printf("NONE (Unknown type)\n");
		return;
	}
	if (e_type == ET_REL)
	{
		printf("REL (Relocatable file)\n");
		return;
	}
	if (e_type == ET_EXEC)
	{
		printf("EXEC (Executable file)\n");
		return;
	}
	if (e_type == ET_NONE)
	{
		printf("DYN (Shared object file)\n");
		return;
	}
	if (e_type == ET_CORE)
	{
		printf("CORE (Core file)\n");
		return;
	}
}
/**
 * entrypointaddr - print entry point address
 * @h: the elf header
 */
void entrypointaddr(Elf64_Ehdr *h)
{
	unsigned long int e = h->e_entry;

	printf("  Entry point address:               ");

	if (h->e_ident[4] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e);
	else
		printf("%#lx\n", e);
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
	int fd, rd, c;
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
	data(header);
	version(header);
	osabi(header);
	abiversion(header);
	type(header);
	entrypointaddr(header);

	free(header);
	c = close(fd);
	if (c < 0)
		error(98, "Error: Can't close elf file %s\n", elf);

	return (0);
}
