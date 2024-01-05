#include "shell.h"
/**
 * handle_commands - .
 * @line: line
 * Return: void
 */
void print_commands(char *line)
{
	int x = _strlen(line);
	int y = 0;
	int z = 0;
	/* print_commands */
	for (y = 0; y < x; y++)
	{
		if (line[y] == ' ')
		{
			z = 0;
		}
		else if (line[y] == '#')
		{
			if (!z)
			{
				line[y] = '\0';
				break;
			}
		}
		else
		{
			z = 1;
		}
	}
}

/**
 * _cd - changes the current directory
 * @line_vector: The vector containing the command and arguments
 * @argv:The program name
 *
 * Return: -1 on failure
 */

int _cd(char **line_vector, char **argv)
{
	char *dir = line_vector[1];
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (1);
	}
	if (dir == NULL || _strcmp(dir, "~") == 0)
		dir = _get_env("HOME");
	else if (_strcmp(dir, "_") == 0)
		dir = _get_env("OLDPWD");
	if (chdir(dir) == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 3);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line_vector[0], _strlen(line_vector[0]));
		write(STDERR_FILENO, ": can't cd to", 14);
		write(STDERR_FILENO, line_vector[1], _strlen(line_vector[1]));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	else
	{
		setenv("OLDPWD", cwd, 1);
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd() error");
			return (1);
		}
	}
	return (0);
}
/**
 * free_all - free all resources
 * @lines: lines to free
 * @counter: counter of free_all
 * @_list_paths: list of paths
 * @env: environment variable
 * @current: Current variable
 * @line: line number
 * @line_vector: line_vector
 * @free_list: free list of free
 * @free_li_vec: free list of vector
 * Return: void
 *
 */
void free_all(char **lines, int counter, _list_paths *env,
		_list_paths *current, char *line, char **line_vector)
{
	if (lines)
	{
		free(lines[counter]);
		if (lines)
			free(lines);
	}
	free_list(env);
	free_list(current);
	free_li_vec(line, line_vector);
}
