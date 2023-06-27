#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _fork(char *token, char **args);
int _perror(char *filename, int commmand_number, char *wrong_command);

#endif
