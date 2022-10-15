#include "main.h"
#include "slist.h"

slist *head = NULL;

extern int command_type;

void execute_internal_commands(char *input_string)
{
    //exit,cd,pwd
    const char *path, *backup_path;

    //if input_string is exit, then terminate the msh shell
    if (strcmp("exit", input_string) == 0)
    {
        exit(1);
    }

    //if pwd command is entered, display the current working directory
    else if (strcmp("pwd", input_string) == 0)
    {
        system("pwd");
    }

    //if cd command is entered, execute command using chdir system call
    else if (strncmp("cd", input_string, 2) == 0)
    {
        //Discard the command
        path = strtok(input_string, " ");

        //Extract the path
        while (path != NULL)
        {
            backup_path = path;
            path = strtok(NULL, " ");
        }

        chdir(backup_path);
    }

    if (strcmp("jobs", input_string) == 0)
    {
        print_list(head);
    }

    if (strcmp("fg", input_string) == 0)
    {
        pid_t pid = get_last_element(head); 
        delete_last(&head);
        kill(pid, SIGCONT);    
        waitpid(getpgid(pid), NULL, 0);
    }
}
