#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - function
 *
 * Return: 0
 *
 */

int main(void)
{
	char *args[] = {" ", NULL};

	while (1)
	{
		char *word = NULL;
		size_t length = 0;
		ssize_t r = 0;

		printf("Waiting for your command: \n");
		r = getline(&word, &length, stdin);

		if (r == -1)
		{
			perror("Error");
			exit(1);
		}
		else if (r != -1)
		{
			execve(word, args, __environ);
			perror("execve");
			exit(1);
		}
	}

	return (0);
}
