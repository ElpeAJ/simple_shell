#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *
 *
 *
 *
 */

int main(int argc, char **args, char **env)
{
	char args[] = {NULL};
	char env[] = {NULL};
	
	printf("$:\n");
	r = getline(&command, &args_size, stdin);
