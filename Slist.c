#include "inverted.h"

int insert_last(Slist **head,char *file)
{
	Slist *new=malloc(sizeof(Slist));	//Creating new node to insert
	if(new==NULL)
		return FAILURE;
	strcpy(new->name,file);		//inserting file name in node
	new->link=NULL;
	if(*head==NULL)		//if list empty inserting first node
	{
		*head=new;
		return SUCCESS;
	}
	Slist *temp=*head;	//traverse through list
	Slist *prev=*head;
	while(temp)
	{
		if(strcmp(temp->name,file)==0)	//if duplicated found return
		{
			printf("Duplicate Found for filr %s\n",file);
			return FAILURE;
		}
		prev=temp;		//else update prev and temp
		temp=temp->link;
	}
	prev->link=new;	//link new node to last node
	return SUCCESS;
}

void print_list(Slist *head)	//printind single linked list
{
	if(head==NULL)
		return;
	while(head)				//traversing through each node and displaying
	{
		if(head->link==NULL)
		{
			printf("%s\n",head->name);
			return;
		}
		printf("%s -> ",head->name);
		head=head->link;
	}

}
