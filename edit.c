#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "structs.h"
#include "main_func.h"
#include "log.h"
#include "sign_up.h"

char edit_words[7][1000],edit_line[1000]="";

void rewriteLine(char* addr, int lineNum, const char* newLine) {
    FILE* file = fopen(addr, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char lines[1024][1024];
    int numLines = 0;
    while (fgets(lines[numLines], 1024, file)) {
        numLines++;
    }

    fclose(file);

    if (lineNum < 1 || lineNum > numLines) {
        printf("Invalid line number\n");
        return;
    }

    strcpy(lines[lineNum - 1], newLine);

    file = fopen(addr, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    int i;
    for (i = 0; i < numLines; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
}

void make_new_line()
{
	sprintf(edit_line, "%s %s %s %s %s %s %s", edit_words[0], edit_words[1], edit_words[2], edit_words[3], edit_words[4], edit_words[5], edit_words[6]);
}

void print_menue() {
  system("cls");
  printf("\n\n\t\t\tMenu\n");
  printf("\t\t\t1. Edit user name: %s\n",edit_words[0]);
  printf("\t\t\t2. Edit password: %s\n",edit_words[1]);
  printf("\t\t\t3. Edit email: %s\n",edit_words[2]);
  printf("\t\t\t4. Edit number: 09%s\n",edit_words[3]);
  printf("\t\t\t5. Edit melicode: %s\n",edit_words[4]);
  printf("\t\t\t6. Edit first name: %s\n",edit_words[5]);
  printf("\t\t\t7. Edit last name: %s\n",edit_words[6]);
  printf("\t\t\t8. save\n");
  printf("\t\t\t9. Quit editting\n");
  printf("\t\t\t10. Quit\n\n");
  printf("\t\t\tEnter your choice: ");
}

void edit_ac(int id,char* addr)
{
	char *line = get_line(id,addr),backup_line[1000],st[1000];
	strcpy(backup_line,line);
	char ch,password[MAX_PASSWORD_LENGTH];
	for(int i=0;i<7;i++)
	{
		printf("%d",i);
		strcpy(edit_words[i],line_to_word(i,line));
		strcpy(line,backup_line);
	}		
	int choice,us_id,choice2;
	do {
		print_menue();
		scanf("%d", &choice);
    	getchar();
    	switch (choice) {
        	case 1:
        		print_up_header();
        		while(1) {
    				printf("Enter a username: ");
    				gets(st);
    				if(strcmp(st,"*")==0)
    					break;
    				else if(strlen(st)<3){
    					print_up_header();
    					printf("username should be bigger than 2 character\n");
    				}
    				else 
    				{
    					strcpy(st,replace_space_with_underscore(st));//check unique
    					if(search_data(USERNAME_ID,USER_FILE_ADDR,st))
    					{
    						print_up_header();
    						printf("username is exist in our directory\n");
						}
						else
							break;
					}
    			}
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 2:
            	print_up_header();
    			while(1) {
    				printf("Enter a password ");
    				for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        				ch = getch();

        				if (ch == 13) { // 13 is the ASCII code for the Enter key
        			    	password[i] = '\0';
        			    	break;
        				}
        				else if (ch == 8) { // 8 is the ASCII code for the Backspace key
        			    	if (i > 0) {
        			        	printf("\b \b"); // erase the character
        			        	i--;
        			        	password[i] = '\0';
        			    	}
        			    	i++;
        				}
        				else {
        			    	password[i] = ch;
        			    	printf("*");
        				}
    				}
    				strcpy(st,password);
    				if(strcmp(st,"*")==0)
    					break;
    				else if(strlen(st)<7){
						print_up_header();
    					printf("password should be bigger than 7 character\n");
    				}
    				else if(have_space(st)){
						print_up_header();
    					printf("do not use space\n");
    				}
    				else
    					break;
    			}
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 3:
            	print_up_header();
    			while(1) {
    				printf("Enter a email: ");
    				gets(st);
    				if(strcmp(st,"*")==0)
    					break;
    				else if(!is_email(st)){
						print_up_header();
    					printf("email is not valid\n");
    				}
    				else if(search_data(EMAIL_ID,USER_FILE_ADDR,st)){
						print_up_header();
    					printf("email is exist in our directory\n");
    				}
    				else
    					break;
    			}
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 4:
            	print_up_header();
    			while(1) {
    				printf("Enter a phone number:09");
    				gets(st);
    				if(strcmp(st,"*")==0)
    					break;
    				else if(strlen(st)!=9){
						print_up_header();
    					printf("phone number should be 11 number\n");
    				}
					else if(!is_numeric(st)){
						print_up_header();
						printf("phone number should be numeric\n");
					}
    				else if(search_data(NUMBER_ID,USER_FILE_ADDR,st)){
						print_up_header();
    					printf("phone number is exist in our directory\n");
    				}
    				else
    					break;
    			}
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 5:
            	print_up_header();
    			while(1) {
    				printf("Enter a meli code: ");
    				gets(st);
    				if(strcmp(st,"*")==0)
    					break;
    				else if(strlen(st)!=10){
						print_up_header();
    					printf("meli code should be 10 number\n");
					}
    				else if(!is_numeric(st)){
						print_up_header();
						printf("meli code should be numeric\n");
					}
    				else if(search_data(MELICODE_ID,USER_FILE_ADDR,st)){
						print_up_header();
    					printf("meli code is exist in our directory\n");
    				}
    				else
    					break;
    			}
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 6:
            	print_up_header();
    			while(1) {
    				printf("Enter a first name: ");
   			 		gets(st);
   			 		if(strcmp(st,"*")==0)
   			 			break;
   			 		else if(strlen(st)<3){
   			 			print_up_header();
    					printf("first name should be bigger than 2 character\n");
    				}
    				else
    					break;	
    			}
    			strcpy(st,replace_space_with_underscore(st));
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 7:
            	print_up_header();
    			while(1) {
    				printf("Enter a last name: ");
    				gets(st);
    				if(strcmp(st,"*")==0)
    					break;
    				else if(strlen(st)<3){
						print_up_header();
    					printf("last name should be bigger than 2 character\n");
    				}
    				else
    					break;
    			}
    			strcpy(st,replace_space_with_underscore(st));
    			if(strcmp(st,"*")!=0)
    				strcpy(edit_words[choice-1],st);
            	break;
            case 8:
            	print_up_header();
            	printf("Are you ok to save 1=yes or other number=no: ");
            	scanf("%d", &choice2);
    			getchar();
            	if(choice2==1)
            	{
            		make_new_line();
            		rewriteLine(addr,id,edit_line);
            		make_log(id,0,EDIT_PROF,".");
            		print_up_header();
            		printf("your account edited where do you want to go edit page=1 back to main menu=other number ");
            		scanf("%d", &choice2);
            		getchar();
            		if(choice2!=1)
    					return ;
    			}
            	break;
        	case 10:
        		exit(0);
        		break;
        	default:
            	break;
      	}
	} while (choice != 9);
//	struct st_user edituser;

}