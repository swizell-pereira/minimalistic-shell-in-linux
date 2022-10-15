#include "main.h"
#include"slist.h"

pid_t pid; //stores process id of parent and child
extern slist *head;

void scan_input(char *prompt, char *input_string)
{
    char *command = NULL;
    int command_type;
    int ret_status;
    int proc_status;

    //signal registration 
    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGTSTP, signal_handler) == SIG_ERR)
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    while (1) //Super loop
    {
        //display the prompt
        printf(ANSI_COLOR_RED "[%s]$" ANSI_COLOR_RESET, prompt);

        //flush output buffer
        fflush(stdout);

        //Scan input till there is '\n'
        scanf("%[^\n]s", input_string);

         // flush i/p buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        //To change prompt
        if (!strncmp("PS1=", input_string, 4))
        {
            if (input_string[4] != ' ') //prompt should not change when white space occurs after PS1=
            {
                strcpy(prompt, &input_string[4]);
                memset(input_string, '\0', 25); //clear input buffer
                continue;
            }
        }

        //extracting only command part
        command = get_command(input_string);

        //check command type whether builtin, external or no command
        command_type = check_command_type(command);

        if (command_type == NO_COMMAND)
        {
            continue;
        }
        else if (command_type == NOT_COMMAND)
        {
            printf("%s: Command not founnd\n", input_string);
        }
        else if (command_type == EXTERNAL) //External commands are executed in a child process
        {
            
            pid = fork();  //create a child

            if (pid == -1) //error handling
            {
                perror("fork");
                exit(1);
            }
            else if (!pid) //child
            {
                ret_status = system(input_string);

                if (!ret_status)
                    exit(0); //success if  0
                else
                    exit(1); //failure if  1
            }
            else //parent
            {
                waitpid(-1, &proc_status, WUNTRACED | WCONTINUED);

                //checking return status of child 
                if (WIFEXITED(proc_status))
                {
                    printf("\nChild with PID: %d terminated normally\n", pid);
                }
                if (WIFSIGNALED(proc_status))
                {
                    printf("\nchild with PID: %d terminated by signalling\n", pid);
                    printf("Sig#: %d\n", WTERMSIG(proc_status));
                }
                if (WIFSTOPPED(proc_status))
                {
                    insert_last(&head, pid, input_string);
                    print_last_element(head);
                }
            }
        }
        else if (command_type == BUILTIN) //internel commands in shell
        {
            execute_internal_commands(input_string);
        }

        //echo function to print the $?, $$, $SHELL
        echo(input_string, proc_status);

        memset(input_string, '\0', 25); //Clear input string buffer for next itteration
    }
}
