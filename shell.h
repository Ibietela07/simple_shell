#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>

#define MAX_LINE_LENGTH 1024

int print_world(void);
void execute_command(char* command);
void handle_the_script(int argc, char *argv[]);
void run_command(char *command, char **arguments);
char *finding_full_path(const char *command);
int startsWith(const char *str, const char *prefix);
void process_cmdline(char **cmd_line);
int my_builtins(char **command);
int execute_set(const char *env_variable, const char *data);
void execute_env(char **args);
int execute_setenv(const char *env_variable);
char *my_getline();
void my_cd(char **args);
void tokenize_input(char *input_data);
int user_input(char **input, size_t *data);
void handle_script_mode(int argc, char *argv[]);
void my_exit(char **args, int *status);
void exit_shell(int status);
extern char **environ;

#endif /* SHELL_H */
