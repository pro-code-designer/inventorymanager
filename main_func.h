#ifndef MAIN_FUNC_INCLUDED
#define MAIN_FUNC_INCLUDED

#include <stdbool.h>

bool is_numeric(char *s) ;
bool is_email(char *email);
char* replace_space_with_underscore(char* str);
int search_data(int id,char *addr,char *search);
char* get_line(int line_num,char *addr);
char* line_to_word(int id,char *line);
bool have_space(char *s);
#endif