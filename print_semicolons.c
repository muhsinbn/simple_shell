#include "shell.h"
#include <stdio.h>

/**
 * print_error - print ERROR messags based on ERROR type.
 * @program_shell: Shell program name
 * @counter: Command counter.
 * @command: Command that caused the ERROR.
 * @type_of_error: Type of error
 * Return: void
 */
void print_error(char *program_shell, int counter,
		char *command, int type_of_error)
{
	char *alx_s;

	alx_s = number_to_char(counter);
	write(STDERR_FILENO, program_shell, _strlen(program_shell));
	write(STDERR_FILENO, ":	", 2);
	write(STDERR_FILENO, alx_s, _strlen(alx_s));
	write(STDERR_FILENO, ":	", 2);
	if (type_of_error == EXIT_ERROR)
		write(STDERR_FILENO, "exit", 4);
	else
		write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ":	", 2);
	if (type_of_error == NOT_FOUND)
		write(STDERR_FILENO, "not found\n", 10);
	else if (type_of_error == PERMISSION_DENIED)
		write(STDERR_FILENO, "Permission denied\n", 18);
	else if (type_of_error == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, "\n", 1);
	}
	free(alx_s);
}

/**
 * print_cant_open - Print error message for a file that can't be openned.
 * @program_shell: shell program name
 * @counter: command counter
 * @file_name:name of the file that can't be openned
 * Return: void
 */
void print_cant_open(char *program_shell, int counter, char *file_name)
{
	char *alx_s;

	alx_s = number_to_char(counter);
	write(STDERR_FILENO, program_shell, _strlen(program_shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, alx_s, _strlen(alx_s));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Can't open ", 11);
	write(STDERR_FILENO, file_name, _strlen(file_name));
	write(STDERR_FILENO, "\n", 1);
	free(alx_s);
}
