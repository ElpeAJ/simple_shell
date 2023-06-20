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
	while (1)
	{
	char *word;
	size_t length;
	ssize_t r;

	printf("Waiting for your command: \n");
	r = getline(&word, &length, stdin);

	if (r == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (r != -1)
	{
		printf("Command read: %s", word);
	}
	}

	return (0);
}
