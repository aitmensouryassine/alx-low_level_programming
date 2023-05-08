#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error - print error and exit with code
 * @code: the error code
 * @msg: the error msg
 * @str: a string
 */
void error(int code, char *msg, char *str)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, str);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success,
 * 97 number of argument is not the correct one
 * 98 file_from does not exist, or if you can not read it
 * 99 can not create or if write to file_to fails
 * 100 can not close a file descriptor
 */
int main(int argc, char **argv)
{
	char *file_to, *file_from;
	char *buffer[BUFFER_SIZE];
	int op_from, op_to, rd_from, cl, wr_to;

	if (argc != 3)
		error(97, "Usage: cp file_from file_to", "");

	file_from = argv[1];
	file_to = argv[2];

	op_from = open(file_from, O_RDONLY);
	if (op_from < 0)
		error(98, "Error: Can't read from file ", file_from);

	op_to = creat(file_to, 0664);
	if (op_to < 0)
		error(99, "Error: Can't write to ", file_to);

	while ((rd_from = read(op_from, buffer, BUFFER_SIZE)) > 0)
	{
		wr_to = write(op_to, buffer, rd_from);
		if (wr_to < 0)
			error(99, "Error: Can't write to ", file_to);
	}

	cl = close(op_from);
	if (cl < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", op_from);
		exit(100);
	}
	cl = close(op_to);
	if (cl < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", op_to);
		exit(100);
	}

	return (0);
}
