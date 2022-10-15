
/*
 * Author: Swizell Pereira
 * Date  : 13 Sept 2020
 * Title : Mini shell
 *Descriptions   : TO create a minishell to implement internal as well as externel commands
 */


#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[])
{
    
    system("clear");  //clear o/p screen

    
    char prompt[25] = "msh";  // to store i/p strinc

    //To store the command/s entered by the user
    char input_string[25]={"\0"};

    //scan input string entered by the user
    scan_input(prompt, input_string);
}
