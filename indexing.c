#include "inverted.h"

int read_and_validate_args(char *file)
{
	if(strstr(file,".txt")!=NULL)		//Checking if exitension is .txt or not
	{
		FILE *fptr=fopen(file,"r");		//opening file
		if(fptr==NULL)					//checking if file opened successfully
		{
			printf("Error in opening %s file\n",file);	
			return FAILURE;
		}
		fseek(fptr,0,SEEK_END);		//moving file to end
		if(ftell(fptr)!=0)			//if size is 0 bytes it is empty
		{
			fclose(fptr);			//closing file
			return SUCCESS;
		}
		else
		{
			printf("%s is Empty file\n",file);		//Printing error messages	
			return FAILURE;
		}
	}
	else
	{
		printf("%s is not .txt file\n",file);
		return FAILURE;
	}
	
}
