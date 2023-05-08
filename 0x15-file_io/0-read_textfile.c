#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the
 * POSIX standard output.
 * @filename: FILE pointer
 * @letters: number of letters it could read and print
 * Return: the actual number of letters it could read and print
 * or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer = malloc(sizeof(char) * letters);
	int sz_rd = 0;

	if (!filename || !buffer)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	sz_rd = read(fd, buffer, letters);
	if (sz_rd < 0)
		return (0);

	sz_rd = write(STDOUT_FILENO, buffer, sz_rd);
	if (sz_rd < 0)
		return (0);

	close(fd);
	free(buffer);
	return (sz_rd);
}
