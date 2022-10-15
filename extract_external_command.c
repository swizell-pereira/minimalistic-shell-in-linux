#include"main.h"

void extract_external_commands(char **external_commands)
{
    //variable declaration
    int fd;
    int i = 0,j = 0;
    char buff[25] = {'\0'};
    char ch;

    //open file in read mode
    fd = open("/home/swizell/ECEP/LinuxInternals/Project/external_commands.txt", O_RDONLY);
    if(fd == -1) //error check
    {
        perror("open");
        exit(1);
    }

    //Read the command one by one and store it in external_command array of pointers
    while(read(fd, &ch, 1) > 0)
    {
        if(ch != '\n')
        {
            buff[i++] = ch;
        }
        else
        {
            //Allocate  memory dynamically
            external_commands[j] = calloc(strlen(buff) + 1, sizeof(char));
            
            //copy the contents
            strcpy(external_commands[j],buff);

            //Append NULL char at the end of each commannd
            external_commands[++j] = '\0';       
            
            //clear buff
            memset(buff,'\0', 25);

            //Re-initialise var
            i = 0;

        }
        
    }
}
