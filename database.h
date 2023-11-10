#ifndef DATA_H
#define DATA_H

#include "inverted.h"

/*creating structure for Subnode*/
typedef struct Subnode
{
	int word_count;
	char file_name[30];
	struct Subnode *next;
}Sub;

/*creating structure for Main node*/
typedef struct Mainnode
{
	char word[30];
	int file_count;
	struct Mainnode *main_link;
	struct Subnode *sub_link;
}Main;

/*Declaration of functions*/
int create_database(Slist **head,Main *arr[]);
int display_database(Main *arr[]);
int search_database(Main *arr[],char *str);
int save_database(Main *arr[],char *fname);
int update_database(Main *arr[],char *fname);
#endif
