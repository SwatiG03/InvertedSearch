#include "inverted.h"
#include "database.h"

int save_database(Main *arr[],char *fname)
{
	FILE *fptr=fopen(fname,"w");	//Opening file
	if(fptr==NULL)
	{
		perror("fptr");
		return FAILURE;
	}
	for(int i=0;i<27;i++)	//traversing through each index
	{
		if(arr[i]!=NULL)	//checking for non empty node
		{
			Main *temp_m=arr[i];
			while(temp_m)	//traversing through main nodes						
			{
				fprintf(fptr,"#");		//writing word and file count to file
				fprintf(fptr,"%d;",i);
				fprintf(fptr,"%s;%d;",temp_m->word,temp_m->file_count);
				Sub *temp_s=temp_m->sub_link;
				while(temp_s)	//Traversing through sub node
				{
					if(temp_s->next!=NULL)		//writing word count and file name to file
						fprintf(fptr,"%s;%d;",temp_s->file_name,temp_s->word_count);
					else
						fprintf(fptr,"%s;%d",temp_s->file_name,temp_s->word_count);
					temp_s=temp_s->next;	//updating link of sub node
				}
				fprintf(fptr,"#\n");
				temp_m=temp_m->main_link;		//updating link of main node
			}
		}
	}
	fclose(fptr);
	return SUCCESS;
}
