#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: name of the file
 * @letters: number of letters to read and print
 *
 * Return: number of letters actually printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t r_bytes, w_bytes, total_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(fd);
        return (0);
    }

    r_bytes = read(fd, buffer, letters);
    if (r_bytes == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    total_written = write(STDOUT_FILENO, buffer, r_bytes);
    if (total_written == -1 || total_written != r_bytes)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);

    return (total_written);
}
