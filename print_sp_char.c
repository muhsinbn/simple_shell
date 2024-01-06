#include "shell.h"
#include <stdio.h>

/**
 * get_command_from_user - get a command from the user as special characters
 * @current: The current variable.
 * Return: The entered line
 */
char *get_command_from_user(_list_paths *current)
{
	ssize_t alx;
	size_t a = 0;
	char *line = NULL;

	write(STDOUT_FILENO, "muhsin$", 7);
	alx = _getline(&line, &a, stdin);
	if (alx == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		free_list(current);
		exit(0);
	}
		if (line[0] == '\n' && alx == 1)
	{
		free(line);
		return (NULL);
	}
	line[alx - 1] = '\0';

	return (line);
}

/**
 * get_command_from_file - Get a command from a file
 * @file: The file to read from.
 *
 * Return: The content of the file.
 */
char *get_command_from_file(char *file)
{
	return (file);
}
