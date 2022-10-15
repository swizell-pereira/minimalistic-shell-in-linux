#ifndef MAIN_H
#define MAIN_H

#define FOREGROUND 'F'
#define BACKGROUND 'B'
#define SUSPENDED 'S'
#define WAITING_INPUT 'W'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void scan_input(char *prompt, char *input_string);
char *get_command(char *input_string);
void extract_external_commands(char **external_commands);
void echo(char *input_string, int status);
int check_command_type(char *command);
void execute_internal_commands(char *input_string);
void signal_handler(int sig_num);

#define BUILTIN 1
#define EXTERNAL 2
#define NO_COMMAND 3
#define NOT_COMMAND 4

#define ANSI_COLOR_RED "\x1b[31m"      //colours
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

/* void populateCommand();
void destroyCommand();
insertJob();
delJob();
getJob();
void printJobs();
void welcomeScreen();
void shellPrompt();
void handleUserCommand();
int checkBuiltInCommands();
void executeCommand();
void launchJob();
void putJobForeground();
void putJobBackground();
void waitJob(t_job* job);
void killJob(int jobId);
void changeDirectory();
void init();
void signalHandler_child(int p); */
#endif
