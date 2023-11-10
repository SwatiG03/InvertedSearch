#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

/*Structure for list to insert file name*/
typedef struct Node
{
	char name[30];
	struct Node *link;
}Slist;

/*Declaration of functions*/
int read_and_validate_args(char *str);
int insert_last(Slist **head,char *str);
void print_list(Slist *head);

#endif
