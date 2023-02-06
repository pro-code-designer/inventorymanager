#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
#include "main_func.h"
#include "edit.h"
#include "log.h"

struct Node* head;

void print_list(struct Node* chap,int number) {
	switch(number){
		case 0:
    		printf("id=%s name=%s brand=%s model=%s price=%s balance=%s more info=%s\n",chap->product.id, chap->product.name, chap->product.brand, chap->product.model, chap->product.price, chap->product.balance, chap->product.more_info);
			break;
		case 1:
    		printf("id=%s\n",chap->product.id);
			break;
		case 2:
    		printf("name=%s\n",chap->product.name);
			break;
		case 3:
    		printf("brand=%s\n",chap->product.brand);
			break;
		case 4:
    		printf("model=%s\n",chap->product.model);
			break;
		case 5:
    		printf("price=%s\n",chap->product.price);
			break;
		case 6:
    		printf("balance=%s\n",chap->product.balance);
			break;
		case 7:
    		printf("more info=%s\n",chap->product.more_info);
			break;
		default:
			return;		
	}
}

struct Node* search(int activation,int data_id, char *data,int number) {
	system("cls");
    struct Node* temp = head;
    while (temp != NULL) {
    	if (activation==2)
    	{
    		if(atof(temp->product.balance)>number)
    			print_list(temp,0);
		}
    	else if (activation==3)
    	{
    		if(atof(temp->product.balance)<number)
    			print_list(temp,0);
    	}
    	else{
    	switch(data_id)
    	{
    		case KID_ID:
    			if (strcmp(temp->product.id,data)==0) 
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
    		case KNAME_ID:
    			if (strcmp(temp->product.name,data)==0)
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
    		case KBRAND_ID:
    			if (strcmp(temp->product.brand,data)==0)
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
    		case KMODEL_ID:
    			if (strcmp(temp->product.balance,data)==0) 
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
    		case KPRICE_ID:
    			if (strcmp(temp->product.balance,data)==0)
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
    		case KBALANCE_ID:
    			if (strcmp(temp->product.balance,data)==0)
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
    		case KMORE_ID:
    			if (strcmp(temp->product.more_info,data)==0)
    				if (activation==1)
    					return temp;
    				else
    					print_list(temp,number);
    			break;
		}
    	}
        temp = temp->next;
    }
    return NULL;
}

struct Node* change_value(int data_id, char *data,int value_change) {
    struct Node* s=search(1,data_id,data,0);
    if (s==NULL)
    {
    	printf("nothing found with this id\n");
    	printf("press any key to continue");
    	getch();
    	return NULL;
    }
    int a=atof(s->product.balance);//string to int
	if(a+value_change>=0)
	{
		printf("before:");print_list(s,0);		
		a+=value_change;
		itoa(a, s->product.balance, 10);//int to string
		printf("after:");print_list(s,0);
	}
	else    
	{                     
    	printf("Your balance is not sufficient for this transaction you have only %s\n",s->product.balance);
    	printf("press any key to continue");
    	getch();
    	return NULL;
	}
	return s;
}

void print_add_header()
{
	system("cls");
	printf("\n\n\t\t\tif you want go back just type *\n\n\n");	
}


int add_up(int last_id,int userid) {
	print_add_header();
	
	struct Product nproduct;
	
    while(1) {
    	printf("Enter a product name: ");
    	gets(nproduct.name);
    	if(strcmp(nproduct.name,"*")==0)
    		return 0;
    	else if(strlen(nproduct.name)<3){
    		print_add_header();
    		printf("name should be biger than 2 character\n");
    	}
    	else 
			break;
    }

    print_add_header();
    while(1) {
    	printf("Enter a brand name: ");
    	gets(nproduct.brand);
    	if(strcmp(nproduct.brand,"*")==0)
    		return 0;
    	else if(strlen(nproduct.brand)<3){
    		print_add_header();
    		printf("brand name should be biger than 2 character\n");
    	}
    	else
    		break;	
    }
    strcpy(nproduct.brand,replace_space_with_underscore(nproduct.brand));
    
    print_add_header();
    while(1) {
    	printf("Enter a model name: ");
    	gets(nproduct.model);
    	if(strcmp(nproduct.model,"*")==0)
    		return 0;
    	else if(strlen(nproduct.model)<3){
			print_add_header();
    		printf("last model should be biger than 2 character\n");
    	}
    	else
    		break;
    }
    strcpy(nproduct.model,replace_space_with_underscore(nproduct.model));
    
    
    print_add_header();
    while(1) {
    	printf("Enter a price: ");
    	gets(nproduct.price);
    	if(strcmp(nproduct.price,"*")==0)
    		return 0;
    	else if(!is_numeric(nproduct.price)){
			print_add_header();
			printf("price should be numeric\n");
		}
    	else
    		break;
    }
    
    print_add_header();
    while(1) {
    	printf("Enter a start value number:");
    	gets(nproduct.balance);
    	if(strcmp(nproduct.balance,"*")==0)
    		return 0;
		else if(!is_numeric(nproduct.balance)){
			print_add_header();
			printf("start value should be numeric\n");
		}
    	else
    		break;
    }
    
    print_add_header();
    while(1) {
    	printf("Enter a more information: ");
    	gets(nproduct.more_info);
    	if(strcmp(nproduct.brand,"*")==0)
    		return 0;
    	else if(strlen(nproduct.name)<2){
    		print_add_header();
    		printf("more information should be biger than 1 character\n");
    	}
    	else
    		break;	
    }
    strcpy(nproduct.brand,replace_space_with_underscore(nproduct.brand));
	
    // Open the file for appending
    FILE *fp = fopen(PRODUCT_FILE_ADDR, "a");
    if (fp == NULL) {
    	system("cls");
    	printf("\n\n\t\t\tError opening file!\n");
    	return 1;
    }

    // Write the name and password to the file
    fprintf(fp, "%d %s %s %s %s %s %s\n", last_id+1 , nproduct.name , nproduct.brand , nproduct.model  , nproduct.price, nproduct.balance , nproduct.more_info );

    // Close the file
    fclose(fp);
    make_log(userid,last_id+1,NEW_PR,nproduct.name);
	system("cls");
	printf("\n\n\t\t\tSuccessfully added!\n");
	return 1;
}



void pmanager(int func_id,int userid)
{
    // Open the file
    head = NULL;
    char sts[1000];
    FILE *file = fopen(PRODUCT_FILE_ADDR, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return ;
    }

	struct Node *lastNode=NULL;
    // Read each line of the file
    char line[100],ss[100];
    int total=0,ptotal=0,make_se;
    char y[10];
    if(func_id==-5)
    {
    	printf("\nyour search id: ");
    	gets(y);
    }
	    int i=0,j=0;
    while (fgets(line, sizeof(line), file)) {
        // Extract the values for name, pass, and email
        struct Product nproduct;
        sscanf(line, "%s %s %s %s %s %s %s",nproduct.id, nproduct.name, nproduct.brand, nproduct.model, nproduct.price, nproduct.balance, nproduct.more_info);
        // Create a new node for the linked list
        if(strcmp(y,nproduct.id)==0)
        {
        	ptotal=atof(nproduct.price)*atof(nproduct.balance);
        	printf("%d",ptotal);
        	printf("\npress any key to continue");
    		getch();
    		fclose(file); 
        	return;
		}
        total+=atof(nproduct.price)*atof(nproduct.balance);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->product = nproduct;
        if(lastNode!=NULL)
        	lastNode->next=newNode;
        newNode->next = NULL;
        lastNode=newNode;
        j++;

        // Insert the new node into the linked list
        if (head == NULL)
            head = newNode;
    }
	if(func_id==-4)
	{
		printf("the total=%d",total);
		printf("\npress any key to continue");
    	getch();
    	fclose(file); 
		return;
	}
    // Close the file
    fclose(file); 
	struct Node* changed;   
    if(func_id<2)
    {
    	char a[10],b[10],c[32];
    	if(func_id==-1)
    	{
    		do{
				printf("how much do you want?: ");
    			gets(b);
    		}while(!is_numeric(b));
	    	search(2,KID_ID,c,atof(b));
	    }
	    if(func_id==-2)
	    {
	    	do{
				printf("how much do you want?: ");
    			gets(b);
    		}while(!is_numeric(b));
	    	search(3,KID_ID,c,atof(b));
		}
    	gets(a);
    	if(!(strcmp(a,"1")==0||strcmp(a,"2")==0||strcmp(a,"3")==0||strcmp(a,"4")==0)&&func_id!=-3)
    		return;
    	if(strcmp(a,"1")!=0||func_id==-3)
    	{
    		if(func_id==-3){
    			printf("\t\t\tyour y: ");
    			gets(b);
    		}
    		else
    			strcpy(b,"0");
    		printf("\t\t\tyour search data: ");
    		gets(c);
    		if(func_id==-3){
				search(1,atof(a)-1,c,atof(b));
    		}
    		search(0,atof(a)-1,c,atof(b));
    		printf("\npress any key to continue");
    		getch();
    		return;
		}
    	printf("\nyour search id: ");
    	gets(c);
    	do{
			printf("how much do you want to change?: ");
    		gets(b);
    	}while(!is_numeric(b));
    	system("cls");
    	if(func_id==0)
    		changed=change_value(atof(a)-1,c,atof(b));
    	else
    		changed=change_value(atof(a)-1,c,-atof(b));
    	if(changed==NULL)
    		return;
    	printf("do you want to save changes? y=yes\n");
    	gets(a);
    	if(strcmp(a,"y")==0)
		{	
			sprintf(sts, "%s %s %s %s %s %s %s\n",changed->product.id, changed->product.name, changed->product.brand, changed->product.model, changed->product.price, changed->product.balance, changed->product.more_info);
			rewriteLine(PRODUCT_FILE_ADDR, atof(changed->product.id), sts);
			if(func_id==0)
			{
				make_se=atof(changed->product.balance)-atof(b);
				sprintf(ss, "%d->%s",make_se, changed->product.balance);
				make_se=atof(changed->product.id);
				make_log(userid,make_se,IN_BAL,ss);
			}
			else
			{
				make_se=atof(changed->product.balance)+atof(b);
				sprintf(ss, "%d->%s",make_se, changed->product.balance);
				make_se=atof(changed->product.id);
				make_log(userid,make_se,DEC_BAL,ss);
			}
				
		}
		else
			return;
	}

	else if(func_id==3)
		add_up(j,userid);
//	struct Node* s=search(0,"1");
//	printf("before: %s %s %s %s %s %s %s\n",s->product.id, s->product.name, s->product.brand, s->product.model, s->product.price, s->product.balance, s->product.more_info);
    return ;
}                      