#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "structs.h"
#include "main_func.h"


struct Lnode* l_head;

int make_log(int userid,int productid,int activityid,char* info) {

    FILE *file;
    time_t current_time;
    char time_string[26];

    // Get the current time
    current_time = time(NULL);

    // Format the time as a string
    strftime(time_string, sizeof(time_string), "%c", localtime(&current_time));

    // Open a file for writing
    file = fopen(LOG_FILE_ADDR, "a");

    // Write the time string to the file
    strcpy(time_string,replace_space_with_underscore(time_string));
    fprintf(file, "%d %d %d %s %s\n", userid,productid,activityid,info,time_string);

    // Close the file
    fclose(file);

    return 0;
}
void print_log_header()
{
	system("cls");
	printf("\n\n\t\t\tif you want go back just type *\n\n\n");	
}



int searchse(int activition,int data_id, time_t *data1,time_t *data2) {
	system("cls");
    struct Lnode* temp = l_head;
    time_t t2;
    int year,month,day,hour,minute,second;
    char st[100];
    struct tm check;
    while (temp != NULL) {
    	sscanf(temp->log.time, "%d/%d/%d_%d:%d:%d", &month, &day, &year, &hour, &minute, &second);
		check.tm_year=year+100;check.tm_mon=month--;check.tm_mday=day;check.tm_hour=hour;check.tm_min=minute;check.tm_sec=second;
		check.tm_isdst = -1;
    	t2=mktime(&check);
		if(atof(temp->log.act_id)==activition||(activition==6&&(atof(temp->log.act_id)==DEC_BAL||atof(temp->log.act_id)==IN_BAL)))
    		if(atof(temp->log.product_id)==data_id)
    			if(*data1<t2&&*data2>t2)
    				if(atof(temp->log.act_id)==IN_BAL)
    					printf("user id=%s increased product id=%s  %s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);
    				else
    					printf("user id=%s decreased product id=%s  %s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);    					
    	temp=temp->next;
	}
	printf("\npress any key to continue");
    getch();
    return 0;
}
void searchue(int id) {
	system("cls");
    struct Lnode* temp = l_head;
    while (temp != NULL) {
		if(atof(temp->log.userid)==id)
    		if(atof(temp->log.act_id)==IN_BAL)
    			printf("user id=%s increased product id=%s  %s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);
    		else if(atof(temp->log.act_id)==DEC_BAL)
    			printf("user id=%s decreased product id=%s  %s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);  
			else if(atof(temp->log.act_id)==NEW_PR)
				printf("user id=%s add product id=%s  with name=%s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);
			else if(atof(temp->log.act_id)==EDIT_PROF)
				printf("user id=%s edit profile in %s\n",temp->log.userid,temp->log.time);
			else
				printf("user id=%s log in %s\n",temp->log.userid,temp->log.time);				
    	temp=temp->next;
	}
	printf("\npress any key to continue");
    getch();
}

void list() {
	system("cls");
    struct Lnode* temp = l_head;
    while (temp != NULL) {
    	if(atof(temp->log.act_id)==IN_BAL)
    		printf("user id=%s increased product id=%s  %s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);
    	else if(atof(temp->log.act_id)==DEC_BAL)
    		printf("user id=%s decreased product id=%s  %s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);  
		else if(atof(temp->log.act_id)==NEW_PR)
			printf("user id=%s add product id=%s  with name=%s in %s\n",temp->log.userid,temp->log.product_id,temp->log.info,temp->log.time);
		else if(atof(temp->log.act_id)==EDIT_PROF)
			printf("user id=%s edit profile in %s\n",temp->log.userid,temp->log.time);
		else
			printf("user id=%s log in %s\n",temp->log.userid,temp->log.time);				
    	temp=temp->next;
	}
	printf("\npress any key to continue");
    getch();
}
int log_time(int func_id,int userid) {
	// func_id=4;
	l_head = NULL;
    char sts[1000];
    FILE *file = fopen(LOG_FILE_ADDR, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }

	struct Lnode *lastLnode=NULL;
    // Read each line of the file
    char line[100],ss[100];
    int make_se;
    while (fgets(line, sizeof(line), file)) {
        // Extract the values for name, pass, and email
        struct st_log nlog;
        sscanf(line, "%s %s %s %s %s",nlog.userid, nlog.product_id, nlog.act_id, nlog.info, nlog.time);
        // Create a new node for the linked list
        struct Lnode *newLnode = malloc(sizeof(struct Lnode));
        newLnode->log = nlog;
        if(lastLnode!=NULL)
        	lastLnode->next=newLnode;
        newLnode->next = NULL;
        lastLnode=newLnode;

        // Insert the new node into the linked list
        if (l_head == NULL)
            l_head = newLnode;
    }
	
    fclose(file); 
    if(func_id<3)
	{
		
        print_log_header();
		printf("%d",func_id);
  		struct tm check;
		char p_id[20];
		struct tm input_time;
    	time_t calendar_time,calendar_time1;
		printf("Enter from the date and time (YYYY MM DD HH MM SS): ");
    	scanf("%d %d %d %d %d %d", &input_time.tm_year, &input_time.tm_mon, &input_time.tm_mday, &input_time.tm_hour, &input_time.tm_min, &input_time.tm_sec);
    	/* Adjust the values to match the format expected by mktime */
    	input_time.tm_year -= 1900; // Year is based on 1900
    	input_time.tm_mon--; // Month is 0-based
    	calendar_time = mktime(&input_time);
    	if (calendar_time == -1) {
        	printf("Invalid input.\n");
        	return NULL;
    	} 
		else {
        	printf("The input corresponds to calendar time: %ld\n", calendar_time);
    	}

        printf("Enter to the date and time (YYYY MM DD HH MM SS): ");
        scanf("%d %d %d %d %d %d", &input_time.tm_year, &input_time.tm_mon, &input_time.tm_mday, &input_time.tm_hour, &input_time.tm_min, &input_time.tm_sec);
        /* Adjust the values to match the format expected by mktime */
        input_time.tm_year -= 1900; // Year is based on 1900
        input_time.tm_mon--; // Month is 0-based
        calendar_time1 = mktime(&input_time);
        if (calendar_time1 == -1) {
            printf("Invalid input.\n");
            return NULL;
        }
        else {
            printf("The input corresponds to calendar time: %ld\n", calendar_time1);
        }

		while(1) {
    		printf("product id:");
    		gets(p_id);
    		if(strcmp(p_id,"*")==0)
    			return 0;
			else if(atoi(p_id)<1){
                print_log_header();
    			printf("product id code should be at least 1 number\n");
			}
    		else if(!is_numeric(p_id)){
                print_log_header();
				printf("product id should be numeric\n");
			}
    		else
    			break;
    	}
    	if(func_id==2)
    		searchse(4,atof(p_id), &calendar_time , &calendar_time1);
    	else if(func_id==1)
    		searchse(5,atof(p_id), &calendar_time , &calendar_time1);
    	else
    		searchse(6,atof(p_id), &calendar_time , &calendar_time1);
    		
	}
	else if(func_id==3)
	{
        print_log_header();
		if(userid!=1)
		{
			printf("you dont have access\n");
			printf("\npress any key to continue");
    		getch();
			return NULL;
		}
		char u_id[20];

		while(1) {

    		printf("user id:");
    		gets(u_id);
    		if(strcmp(u_id,"*")==0)
    			return 0;
			else if(atoi((u_id))<1){
                print_log_header();
    			printf("user id code should be at least 1 number\n");
			}
    		else if(!is_numeric(u_id)){
                print_log_header();
				printf("user id should be numeric\n");
			}
    		else
    			break;
    	}
    	searchue(atof(u_id));
	}
	
	else // func_id == 4
	{
        print_log_header();
		if(userid!=1)
		{
			printf("you dont have access\n");
			printf("\npress any key to continue");
    		getch();
			return NULL;
		}
		list();
	}
    return 0;
}