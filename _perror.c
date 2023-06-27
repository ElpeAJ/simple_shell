#include "main.h"

/**
 * _perror - function that prints error
 * @filename: displayed filename
 * @command_number: Number of command run-time
 *
 * @wrong_command: Output wrong command
 * Return: 127 always
 */

int _perror(char *filename, int command_number, char *wrong_command)
{
	fprintf(stderr, "%s: %d: %s: not found\n", filename,
			command_number, wrong_command);

	return (127);
}
