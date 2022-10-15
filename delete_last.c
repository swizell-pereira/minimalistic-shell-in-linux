#include"slist.h"

int delete_last(slist **head)
{
    //Checking if list empty
    if ( *head == NULL )
	return EMPTY_LIST;

    //Checking if list contains 1 node only
    if ( (*head)->link == NULL )
	return delete_first(head);

    slist *temp = *head;

    //Traversing till last node
    while ( temp->link->link != NULL )
    {
	temp = temp -> link;
    }

    //deleting node
    free(temp->link);
    //Update node link
    temp->link = NULL;
    return SUCCESS;
}
