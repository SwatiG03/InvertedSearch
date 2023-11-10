#include "inverted.h"
#include "database.h"
#include <ctype.h>

int create_database(Slist **head,Main *arr[27])
{
	if(*head==NULL)			//if empty list return
		return FAILURE;
	Slist *list=*head;	
	while(list)			//Traverse through filename
	{
		FILE *fptr=fopen(list->name,"r");	//Open each file
		if(fptr==NULL)
		{
			perror("fptr");
			return FAILURE;
		}
		char store[30];
		while(fscanf(fptr,"%s",store)>0)	//Read each word
		{
			int index=tolower(store[0])%97;		//find index
			if(index>25)
				index=26;
		//	printf("index->%d",index);
		//	printf("%s->",store);
			if(arr[index]==NULL)		//if index position null 
			{
				Main *new_main=malloc(sizeof(Main));	//Create new main and sub node
				Sub *new_sub=malloc(sizeof(Sub));
				if(new_main==NULL || new_sub==NULL)
					return FAILURE;
				strcpy(new_main->word,store);	//insert word to new node
				new_main->file_count=1;			//insert file count to new node
				new_main->main_link=NULL;
				new_main->sub_link=new_sub;		//update sub link to sub node
				new_sub->word_count=1;			//insert word count sub node
				new_sub->next=NULL;
				strcpy(new_sub->file_name,list->name);		//insert file name to sub node
				arr[index]=new_main;
			}
			else
			{
				Main *temp_m=arr[index];
				Main *prev_m=NULL;
				while(temp_m)	//traverse through nodes
				{
					if(strcmp(temp_m->word,store)==0)  //find match
					{
						Sub *temp_s=temp_m->sub_link;	//if found
						Sub *prev_s=NULL;
						while(temp_s)
						{
							if(strcmp(temp_s->file_name,list->name)==0)		//check file name 
							{
								temp_s->word_count++;		//if matches increase word count
								break;								
							}
							else
							{
								prev_s=temp_s;			//else move to next sub node
								temp_s=temp_s->next;
							}
						}
						if(temp_s==NULL)		//if reached last sub node
						{
							temp_m->file_count++;
							Sub *new_s=malloc(sizeof(Sub));			//create sub node
							if(new_s==NULL)
								return FAILURE;
							new_s->word_count=1;		//insert word count to sub node
							strcpy(new_s->file_name,list->name);	//insert file name to sub node
							new_s->next=NULL;
							prev_s->next=new_s;		//update prev sub node link to current node
						}
						break;
					}
					else
					{
						prev_m=temp_m;		//update main node to next main node
						temp_m=temp_m->main_link;
					}
				}
				if(temp_m==NULL)		//if reached end of main  node
				{
					Main *new_main1=malloc(sizeof(Main));		//create new main node and sub node
					Sub *new_sub1=malloc(sizeof(Sub));
					if(new_main1==NULL || new_sub1==NULL)
						return FAILURE;
					strcpy(new_main1->word,store);			//insert word to new main node
					new_main1->file_count=1;				//insert file count as 1 to new main node
					new_main1->main_link=NULL;
					new_main1->sub_link=new_sub1;			//update new main sub libk to sub node
					new_sub1->word_count=1;					//insert word count to sub node
					new_sub1->next=NULL;
					strcpy(new_sub1->file_name,list->name);	//insert filename to sub node
					prev_m->main_link=new_main1;			//update previous main node lint to current main node
				}
			}
		}
		fclose(fptr);
		list=list->link;	//update list to next file
	}
	return SUCCESS;
}
