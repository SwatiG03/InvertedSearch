#include "inverted.h"
#include "database.h"
#include <string.h> 
#include <stdlib.h> 

int update_database(Main *arr[],char *fname)
{
	FILE *fptr=fopen(fname,"r");	//Opening file
	if(fptr==NULL)
	{
		perror("fptr");
		return FAILURE;
	}
	char ch1,ch2;	
	fscanf(fptr,"%c",&ch1);		//Reading first char of file
	fseek(fptr,-2,SEEK_END);
	fscanf(fptr,"%c",&ch2);		//Reading last char file
	if(ch1=='#' && ch2=='#')	//if they match continue 
	{
		printf("Valid file\n");
	}
	else
		return FAILURE;
	for(int i=0;i<27;i++)	//Check is there non NULL in any of array of pointers
	{
		if(arr[i]!=NULL)
			return FAILURE;
	}
	fseek(fptr,0,SEEK_SET);
	char line[100];
	while(fscanf(fptr,"%s",line)>0)		//Traverse through each line
	{
		char *ptr;
		ptr=strtok(line,"#;");	//call strtok to fetch tokens
		int i=atoi(ptr);		//store in index
		Main *temp_m=arr[i];	
		Main *prev_m=NULL;
		while(temp_m)			//Traverse to last node 
		{
			prev_m=temp_m;
			temp_m=temp_m->main_link;
		}
		Main *new_main=malloc(sizeof(Main));	//Create main node 
		if(new_main==NULL)
			return FAILURE;
		ptr=strtok(NULL,"#;");			//fetch word
		strcpy(new_main->word,ptr);		//insert word
		ptr=strtok(NULL,"#;");			//fetch file count
		new_main->file_count=atoi(ptr);	//insert file count
		new_main->main_link=NULL;
		new_main->sub_link=NULL;
		if(prev_m==NULL)			//update previous node link part
			arr[i]=new_main;
		else
			prev_m->main_link=new_main;
		Sub *prev_s=NULL;
		for(int j=0;j<new_main->file_count;j++)		//Create sub nodes based on no.of file counts
		{
			Sub *new_sub=malloc(sizeof(Sub));
			if(new_sub==NULL)
				return FAILURE;
			if(new_main->sub_link==NULL)	//update previous node link
			{
				new_main->sub_link=new_sub;
			}
			else
			{
				prev_s->next=new_sub;
			}
			ptr=strtok(NULL,"#;");		//fetch filename 
			strcpy(new_sub->file_name,ptr);		//insert file name
			ptr=strtok(NULL,"#;");			//fetch word count
			new_sub->word_count=atoi(ptr);	//insert word count
			new_sub->next=NULL;
			prev_s=new_sub;
		}
	}
	fclose(fptr);
	return SUCCESS;

}
