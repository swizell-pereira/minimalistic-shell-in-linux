#include "slist.h"

int insert_last(slist **head, data_type pid, char *command_name)
{
    //Declare pointer and Allocatc memory
    slist *new = malloc(sizeof(slist));
    if (new == NULL) //Valdation
        return FAILURE;

    //Update node values
    new->process_id = pid;
    strcpy(new->command_name, command_name);
    new->link = NULL;

    //Check if list empty
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    //Traverse till last node
    slist *temp = *head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;
    return SUCCESS;
}
