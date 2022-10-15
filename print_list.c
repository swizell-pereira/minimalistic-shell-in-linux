#include "slist.h"

void print_list(slist *head)
{
	int i = 0;
	//Checking if list empty
	if (head == NULL)
		printf("\nList is empty\n");
	else
	{
		while (head != NULL)
		{
			printf("[%d]\tPID: %d\t%s\n",i, head->process_id, head->command_name);
			i++;
			head = head->link;
		}
		printf("\n");
	}
}

void print_last_element(slist *head)
{
	int i = 1;
	//Checking if list empty
	if (head == NULL)
		printf("\nList is empty\n");
	else
	{
		while (head->link != NULL)
		{
			head = head->link;
			i++;
		}
		printf("[%d]\tChild with PID: %d pauses execution due to signal received\n",i, head->process_id);
	}
}


pid_t get_last_element(slist *head)
{
	//Checking if list empty
	if (head == NULL)
		printf("\nList is empty\n");
	else
	{
		while (head->link != NULL)
		{
			head = head->link;
		}
		return head->process_id;
	}
}
