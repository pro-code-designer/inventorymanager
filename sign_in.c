#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "main_func.h"
#include "structs.h"
#include "log.h"

void print_in_header()
{
	system("cls");
	printf("\n\n\t\t\tif you want go back just type *\n\n\n");	
}


int sign_in() {
	print_in_header();
	
	struct st_user newuser;
	int user_id=0;
	
    while(1) {
    	printf("Enter a username: ");
    	gets(newuser.username);
    	if(strcmp(newuser.username,"*")==0)
    		return 0;
    	else 
    	{
    		strcpy(newuser.username,replace_space_with_underscore(newuser.username));//check unique
    		user_id=search_data(USERNAME_ID,USER_FILE_ADDR,newuser.username);
    		if(!user_id){
    			print_in_header();
    			printf("username dose not exist in our directory\n");
    		}
			else
				break;
		}
    }
    
    
    char *str=get_line(user_id,USER_FILE_ADDR);
    printf("%s",str);
    char *password_test=line_to_word(PASSWORD_ID,str);
    
	print_in_header();
    char ch,password[MAX_PASSWORD_LENGTH];
    while(1) {
    	printf("Enter the password: ");
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
            	i--;
        	}
        	else {
            	password[i] = ch;
            	printf("*");
        	}
    	}
    	if(strcmp(password,"*")==0)
    		return 0;
    	else if (strcmp(password,password_test)!=0){
    		print_in_header();
    		printf("passwords are not matching\n");
    	}
    	else
    		break;
    }


	printf("\nSuccessfully signed in!\n");
	make_log(user_id,0,LSIGN_IN,".");
	return user_id;
}