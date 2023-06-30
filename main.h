#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
int _fork(char *token, char **args);
int _perror(char *filename, int commmand_number, char *wrong_command);
char **_tokenizer(char *, char *);
char *_getpath(char *);
void _should_exit(char *, int);

#endif
