#ifndef INVENTORY_INCLUDED
#define INVENTORY_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"



struct Node* search(int data_id, char *data) ;
int change_value(int data_id, char *data,int value_change);
void print_list();
void pmanager();
#endif