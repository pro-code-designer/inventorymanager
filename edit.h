#ifndef EDIT_INCLUDED
#define EDIT_INCLUDED

#include <stdio.h>
#include <string.h>
#include "structs.h"

extern char edit_words[7][1000];
void rewriteLine(char* addr, int lineNum, const char* newLine);
void print_menue(char* word);
void edit_ac(int id,char* addr);

#endif