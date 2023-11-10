/*
Name		  : Swathi Gajaram
Date		  :	03-11-2023 
Description   : Inverted Search Project:/storing the index to optimize the speed and performance for finding relevant documents for a search query,update data,and save data to the updated file.
 */

#include "inverted.h" 
#include "database.h" 

int main(int argc,char *argv[])
{
	Slist *head=NULL;
	Main *arr[27]={};
	if(argc>1)
	{
		for(int i=1;i<argc;i++)
		{
			if(read_and_validate_args(argv[i])==SUCCESS)		//function call to validate argumnets
			{
				printf("Validation of %s file Success\n",argv[i]);			
				if(insert_last(&head,argv[i])==SUCCESS)				//if validate successfull inserting it to list
				{
					printf("Insertion of %s in list is Success\n",argv[i]);
				}
				else
				{
					printf("Error in insertion of %s file\n",argv[i]);
				}
			}
			else
			{
				printf("Error in validating file %s\n",argv[i]);
			}
		}
		print_list(head);
		/*Displaying Menu*/
		printf("1.Create database\n2.Display database\n3.Search database\n4.Save database\n5.Update database\n6.Exit\n");
		int ch;
		while(1)
		{
			printf("Enter your choice: ");
			scanf("%d",&ch);		//Reading choice
			switch(ch)
			{
				case 1:		
					{
						if(create_database(&head,arr)==SUCCESS)		//Calling data base function
							printf("creation successfull\n");
					}
					break;
				case 2:	
					{
						if(display_database(arr)==SUCCESS)		//calling display function
							printf("Display Successful\n");
					}
					break;
				case 3:
					{
						char str[30];
						printf("Enter the word to search: ");	//Reading word from user to search
						scanf(" %s",str);
						if(search_database(arr,str)==FAILURE)	//Calling search function
							printf("Word Not Found\n");
					}
					break;
				case 4:
					{
						char str[30];
						printf("Enter backup filename: ");	//Reading backup filename
						scanf(" %s",str);
						if(strstr(str,".txt")==NULL)		//Checking extension of file
						{
							printf("Error: Filename is not .txt\n");
							break;
						}
						if(save_database(arr,str)==SUCCESS)		//Calling save data base function
							printf("Data Saved\n");
						else
							printf("Data Not Saved\nTry Again!!\n");
					}
					break;
				case 5:
					{
						char str[30];						
						printf("Enter backup filename: ");	//Reading backup filenmae
						scanf(" %s",str);
						if(strstr(str,".txt")==NULL)		//Checking extension
						{
							printf("Error: Filename is not .txt\n");
							break;
						}
						if(update_database(arr,str)==SUCCESS)	//Calling update function
							printf("Updated Database\n");
						else
							printf("Updating Database Failed\n");
					}
					break;
				case 6:			//Exit option
					exit(0);
				default:
					printf("Invalide Choice\n");
			}
		}
	}
	else
	{
		printf("ERROR in Passing Arguments\nUsage: ./a.out <filename.txt> <filename2.txt>.....\n");
	}

	return 0;
}

