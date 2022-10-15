#ifndef SLIST_H
#define SLIST_H 

#include"main.h"
#define SUCCESS -1
#define FAILURE -2
#define EMPTY_LIST -3
#define DATA_NOT_FOUND -4
typedef pid_t data_type;


typedef struct node  {
    data_type process_id;
    char command_name[100];
    struct node *link;

}slist;

int insert_first(slist **head, data_type data);
int insert_last(slist **head, data_type pid, char *command_name);
pid_t get_last_element(slist *head);

int delete_first(slist **head);
int delete_last(slist **head);
int delete_list(slist **head);
int find_node(slist **head, data_type data);
void print_list( slist *head );

void print_last_element(slist *head);


#endif


