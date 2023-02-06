#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "main_func.h"
#include "structs.h"
#include "windows.h"

void print_up_header()
{
	system("cls");
	printf("\n\n\t\t\tif you want go back just type *\n\n\n");	
}


int sign_up() {
	print_up_header();
	int user_id;
	
	struct st_user newuser;
	
    while(1) {
    	printf("Enter a username: ");
    	gets(newuser.username);
    	if(strcmp(newuser.username,"*")==0)
    		return 0;
    	else if(strlen(newuser.username)<3){
    		print_up_header();
    		printf("username should be biger than 2 character\n");
    	}
    	else 
    	{
    		strcpy(newuser.username,replace_space_with_underscore(newuser.username));//check uniqe
    		if(search_data(USERNAME_ID,USER_FILE_ADDR,newuser.username))
    		{
    			print_up_header();
    			printf("username is exist in our directory\n");
			}
			else
				break;
		}
    }

    print_up_header();
    while(1) {
    	printf("Enter a first name: ");
    	gets(newuser.fname);
    	if(strcmp(newuser.fname,"*")==0)
    		return 0;
    	else if(strlen(newuser.fname)<3){
    		print_up_header();
    		printf("first name should be biger than 2 character\n");
    	}
    	else
    		break;	
    }
    strcpy(newuser.fname,replace_space_with_underscore(newuser.fname));
    
    print_up_header();
    while(1) {
    	printf("Enter a last name: ");
    	gets(newuser.lname);
    	if(strcmp(newuser.lname,"*")==0)
    		return 0;
    	else if(strlen(newuser.lname)<3){
			print_up_header();
    		printf("last name should be biger than 2 character\n");
    	}
    	else
    		break;
    }
    strcpy(newuser.lname,replace_space_with_underscore(newuser.lname));
    
    print_up_header();
    while(1) {
    	printf("Enter a email: ");
    	gets(newuser.email);
    	if(strcmp(newuser.email,"*")==0)
    		return 0;
    	else if(!is_email(newuser.email)){
			print_up_header();
    		printf("email is not valid\n");
    	}
    	else if(search_data(EMAIL_ID,USER_FILE_ADDR,newuser.email)){
			print_up_header();
    		printf("email is exist in our directory\n");
    	}
    	else
    		break;
    }
    
    print_up_header();
    while(1) {
    	printf("Enter a meli code: ");
    	gets(newuser.melicode);
    	if(strcmp(newuser.melicode,"*")==0)
    		return 0;
    	else if(strlen(newuser.melicode)!=10){
			print_up_header();
    		printf("meli code should be 10 number\n");
		}
    	else if(!is_numeric(newuser.melicode)){
			print_up_header();
			printf("meli code should be numeric\n");
		}
    	else if(search_data(MELICODE_ID,USER_FILE_ADDR,newuser.melicode)){
			print_up_header();
    		printf("meli code is exist in our directory\n");
    	}
    	else
    		break;
    }
    
    print_up_header();
    while(1) {
    	printf("Enter a phone number:09");
    	gets(newuser.number);
    	if(strcmp(newuser.number,"*")==0)
    		return 0;
    	else if(strlen(newuser.number)!=9){
			print_up_header();
    		printf("phone number should be 11 number\n");
    	}
		else if(!is_numeric(newuser.number)){
			print_up_header();
			printf("phone number should be numeric\n");
		}
    	else if(search_data(NUMBER_ID,USER_FILE_ADDR,newuser.number)){
			print_up_header();
    		printf("phone number is exist in our directory\n");
    	}
    	else
    		break;
    }
    
    char ch,password[MAX_PASSWORD_LENGTH];
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
    	strcpy(newuser.password,password);
    	if(strcmp(newuser.password,"*")==0)
    		return 0;
    	else if(strlen(newuser.password)<8){
			print_up_header();
    		printf("password should be biger than 7 character\n");
    	}
    	else if(have_space(newuser.password)){
			print_up_header();
    		printf("do not use space\n");
    	}
    	else
    		break;
    }
    
    print_up_header();
    while(1) {
    	printf("Renter the password: ");
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
    	if(strcmp(password,"*")==0)
    		return 0;
    	else if (strcmp(password,newuser.password)!=0){
			print_up_header();
    		printf("passwords are not matching\n");
    	}
    	else
    		break;
    }


	
    // Open the file for appending
    FILE *fp = fopen(USER_FILE_ADDR, "a");
    if (fp == NULL) {
    	system("cls");
    	printf("\n\n\t\t\tError opening file!\n");
    	return 1;
    }

    // Write the username and password to the file
    fprintf(fp, "%s %s %s %s %s %s %s\n", newuser.username , newuser.password , newuser.email , newuser.number , newuser.melicode , newuser.fname , newuser.lname );

    // Close the file
    fclose(fp);
	system("cls");
	printf("\n\n\t\t\tSuccessfully signed up!\n");
	return 1;
}