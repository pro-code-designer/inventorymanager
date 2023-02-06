#include "sign_up.h"
#include "sign_in.h"
#include "edit.h"
#include "inventory.h"
#include "log.h"

void print_menu1() {
  system("cls");
  printf("\n\n\t\t\tMenu\n\n");
  printf("\t\t\t1. Sign up\n");
  printf("\t\t\t2. Sign in\n");
  printf("\t\t\t3. Quit\n\n");
  printf("\t\t\tEnter your choice: ");
}

void print_menu2() {
  system("cls");
  printf("\n\n\t\t\tMenu\n\n");
  printf("\t\t\t1. New product\n\n");
  printf("\t\t\t2. Increase a product stock\n\n");
  printf("\t\t\t3. Decrease a product stock\n\n");
  printf("\t\t\t4. Reports\n\n");
  printf("\t\t\t5. Edit account\n\n");
  printf("\t\t\t6. Quit account\n\n");
  printf("\t\t\t7. Quit\n\n");
  printf("\t\t\tEnter your choice: ");
}

void print_menu3() {
  system("cls");
  printf("\n\n\t\t\tMenu\n\n");
  printf("\t\t\t1. change by id\n\n");
  printf("\t\t\t2. search by product name\n\n");
  printf("\t\t\t3. search by product brand\n\n");
  printf("\t\t\t4. search by product model\n\n");
  printf("\t\t\tetc. back\n\n");
  printf("\t\t\tEnter your choice: ");
}

void print_menu4() {
  system("cls");
  printf("\n\n\t\t\tMenu\n\n");
  printf("\t\t\t1. Product inventory\n\n");
  printf("\t\t\t2. search product more than\n\n");
  printf("\t\t\t3. search product less than\n\n");
  printf("\t\t\t4. total networth\n\n");
  printf("\t\t\t5. product networth\n\n");
  printf("\t\t\t6. Increased a product base time\n\n");
  printf("\t\t\t7. Decreased a product base time\n\n");
  printf("\t\t\t8. Decreased and increased a product base time\n\n");
  printf("\t\t\t9. who do what(only admin)\n\n");
  printf("\t\t\t10. all user activity(only admin)\n\n");
  printf("\t\t\tetc. back\n\n");
  printf("\t\t\tEnter your choice: ");
}

void print_menu5() {
  system("cls");
  printf("\n\n\t\t\tMenu\n\n");
  printf("\t\t\tsearch by x=? and get y=?\n\n");
  printf("\t\t\t0. to print everything\n\n");
  printf("\t\t\t1. id\n\n");
  printf("\t\t\t2. product name\n\n");
  printf("\t\t\t3. product brand\n\n");
  printf("\t\t\t4. product model\n\n");
  printf("\t\t\t5. price \n\n");
  printf("\t\t\t6. balance \n\n");
  printf("\t\t\t7. more info \n\n");
  printf("\t\t\tetc. back\n\n");
  printf("\t\t\tEnter your x: ");
}

int main(int argc, char* argv[]) {
	FILE *fp = fopen(PRODUCT_FILE_ADDR, "a");
    if (fp == NULL) {
    	system("cls");
    	printf("\n\n\t\t\tError opening file!\n");
    	return 1;
    }
    fclose(fp);
	int choice,us_id,t;
	do {
		print_menu1();
		scanf("%d", &choice);
    	getchar();
    	switch (choice) {
        	case 1:
            	sign_up();
            	break;
        	case 2:
        		us_id=sign_in();
            	if(us_id!=0)
            	{
            		do {
						print_menu2();
						scanf("%d", &choice);
    					getchar();
    					switch (choice) {
        					case 1:
    							pmanager(3,us_id);
            					break;
            				case 2:
            					print_menu3();
    							pmanager(0,us_id);
            					break;
            				case 3:
            					print_menu3();
    							pmanager(1,us_id);
            					break;
            				case 4:
            					print_menu4();
            					scanf("%d", &choice);
    							getchar();
            					switch(choice)
            					{
            						case 1:
            							print_menu5();
            							pmanager(-3,us_id);
            							break;
            						case 2:
            							pmanager(-1,us_id);
            							break;
            						case 3:
            							pmanager(-2,us_id);
            							break;
            						case 4:
            							pmanager(-4,us_id);
            							break;
            						case 5:
            							pmanager(-5,us_id);
            							break;
            						case 6:
            							log_time(2,us_id);
            							break;            							
            						case 7:
            							log_time(1,us_id);
            							break;
            						case 8:
            							log_time(0,us_id);
            							break;
            						case 9:
            							log_time(3,us_id);
            							break;
            						case 10:
            							log_time(4,us_id);
            							break;
            						default:
            							break;
								}
								break;
        					case 5:
        						edit_ac(us_id,USER_FILE_ADDR);
            					break;
        					case 7:
            					printf("Goodbye!\n");
            					return 0;
        					default:
            					break;
      					}
					} while (choice != 6);
				}
           	break;
        	case 3:
            	printf("Goodbye!\n");
            	break;
        	default:
            	break;
      	}
	} while (choice != 3);
  return 0;
}