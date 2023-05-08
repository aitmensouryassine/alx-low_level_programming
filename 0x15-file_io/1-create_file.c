#include "main.h"

/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: content to be written to the created file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, sz;

	if (!filename)
		return (-1);

	fd = creat(filename, 0600);
	if (fd < 0)
		return (-1);

	if (!text_content)
		text_content = "";
	else
		while (text_content[len])
			len++;

	sz = write(fd, text_content, len);
	if (sz < 0)
		return (-1);

	close(fd);
	return (1);
}
