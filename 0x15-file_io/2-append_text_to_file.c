#include "main.h"

/**
 * append_text_to_file -  appends text at the end of a file.
 * @filename: the file name
 * @text_content: the text to write to the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, sz, len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);

	if (!text_content)
		return (1);

	while (text_content[len])
		len++;

	sz = write(fd, text_content, len);
	if (sz < 0)
		return (-1);

	close(fd);
	return (1);
}
