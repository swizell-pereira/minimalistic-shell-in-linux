#include "slist.h"

int delete_first(slist **head)
{
    //if list empty
    if ( *head == NULL )
	return EMPTY_LIST;
    
    //Storing value of head in temp
    slist *temp = *head;
    //Updating head to next node
    *head = (*head)->link;
    //delete node 
    free(temp);
    return SUCCESS;
} 

