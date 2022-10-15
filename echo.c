#include "main.h"

void echo(char *input_string, int status)
{
    if (strncmp("echo $?", input_string, 7) == 0) //whn i/p str is echo $?
    {
        //exit status
        printf("%d\n", status);
    }
    else if (strncmp("echo $$", input_string, 7) == 0) //when  echo $$
    {
        //pid of minishell
        printf("%d\n", getpid());
    }
    else if (strncmp("echo $SHELL", input_string, 11) == 0) //when echo $SHELL
    {
        //print msh executable path
        system("pwd");
    }
}
