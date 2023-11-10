#include "inverted.h"
#include "database.h"

int display_database(Main *arr[])
{
	printf("%-5s %-10s %-10s %-15s %-5s\n","Index","Word","File_count","File_name","count");
	for(int i=0;i<27;i++)	//Traverse through array of pointers
	{
		if(arr[i]!=NULL)	//if null not fpund
		{
			Main *temp_m=arr[i];
			while(temp_m)		//Traverse through main node
			{
				printf("%-6d",i);		//print index
				printf("%-11s",temp_m->word);		//Print word 
				printf("%-11d",temp_m->file_count);	//Print file count
				Sub *temp_s=temp_m->sub_link;
				while(temp_s)		//traverse through sub nodes
				{
					printf("%-16s",temp_s->file_name);		//Print file name
					printf("%-6d",temp_s->word_count);		//print word count
					temp_s=temp_s->next;	//update to next sub node
				}
				printf("\n");
				temp_m=temp_m->main_link;	//update to next main node
			}
		}
	}
	return SUCCESS;
}
