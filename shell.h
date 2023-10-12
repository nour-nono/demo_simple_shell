#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <sys/wait.h>
#include <fcntl.h>
extern char **environ;

/*is_file*/
void is_file();

/*is_interactive*/
void is_interactive();

/*is_non_interactive*/
void is_non_interactive();

/*token*/
unsigned int is_delim(char c, char *delimiters);
char *_strtok(char *str, char *delimiters);
char **make_arr_of_str(char *str, char *delimiters);

/*string_funcs*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(const char *s1,const char *s2);
char *_strdup(char *str);

/*env_funcs*/
char *_getenv(const char *name);

/*exec_commands*/
char *search_for_command_in_paths(char *command);
void exec_command(char **command_and_argu);

/*free_array*/
void free_array(char ***arr);

#endif
