#include "main.h"

int check_command_type(char *command)
{
    int i;

    //list of all buit in command
    char *builtins[] = {"alias", "bg", "bind", "break", "builtin", "case", "cd", "command", "compgen", "complete", "continue",
                        "declare", "dirs", "disown", "echo", "enable", "eval", "exec", "exit", "export", "fc", "fg", "getopts",
                        "hash", "help", "history", "if", "jobs", "kill", "let", "local", "logout", "popd", "printf", "pushd", "pwd",
                        "read", "readonly", "return", "set", "shift", "shopt", "source", "suspend", "test", "times", "trap", "type",
                        "typeset", "ulimit", "umask", "unalias", "unset", "until", "wait", "while", NULL};

    char *external_commands[155] = {NULL};

    //Checking if command is built in 
    for (i = 0; builtins[i] != NULL; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
        {
            return BUILTIN;
        }
    }
    
    //for external commands
    extract_external_commands(external_commands);

    for (i = 0; external_commands[i] != NULL; i++)
    {
        if (strcmp(command, external_commands[i]) == 0)
        {
            return EXTERNAL;
        }
    }
    
    if(strcmp(command,"\0") != 0)
    {
        return NOT_COMMAND;
    }
    else
    {
        return NO_COMMAND;
    }
    
}
