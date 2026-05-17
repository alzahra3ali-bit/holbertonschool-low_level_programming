#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void close_fd(int fd);
void print_usage(void);
void read_error(char *file);
void write_error(char *file);
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
		print_usage();

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		read_error(argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		write_error(argv[2]);

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
