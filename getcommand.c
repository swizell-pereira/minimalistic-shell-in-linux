#include"main.h"

char *get_command(char *input_string)
{
    static char command[25] = {'\0'};
    char i = 0;

    while(1)
    {
        if(input_string[i] == ' ' || input_string[i] == '\0')
        {
            break;
        }

        //copy string into command variable char by char
        command[i++] = input_string[i];
    }
    
    //Append '\0' at the end
    command[i] = '\0';
    return command;
}
