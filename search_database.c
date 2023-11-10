#include "inverted.h"
#include "database.h"
#include <ctype.h> 

int search_database(Main *arr[27],char *str)
{
	int index=tolower(str[0])%97;	//finding index for given word
	if(index>26)
		index=26;
	Main *temp_m=arr[index];
	while(temp_m)		//traversing thorugh main node
	{
		if(strcmp(temp_m->word,str)==0)		//if word matches
		{
			printf("Word %s is present in %d files\n",str,temp_m->file_count);	//printing file count
			Sub *temp_s=temp_m->sub_link;
			while(temp_s)	//traversing through sub nodes
			{
				printf("%s->%d\n",temp_s->file_name,temp_s->word_count);	//Printing file name and word count
				temp_s=temp_s->next;	//updating to next sub node
			}
			return SUCCESS;
		}
		temp_m=temp_m->main_link;	//upating to next main node
	}
	return FAILURE;



}

