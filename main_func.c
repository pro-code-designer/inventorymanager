#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


bool is_numeric(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}


//---------------------------------------------------------------------------------------------------------------------------


bool have_space(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i]==' ') {
            return 1;
        }
    }
    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------


bool is_email(char *email) {

  int at_index = -1;
  int dot_index = -1;
  int len = strlen(email);

  // Find the position of the @ and . characters
  for (int i = 0; i < len; i++) {
    if (email[i] == '@') {
      at_index = i;
    } else if (email[i] == '.') {
      dot_index = i;
    }
    else if(email[i] == ' ')
  		return 0;
    
  }

  // Check that the @ and . characters are in the correct positions
  if (at_index > 0 && dot_index > at_index + 1 && dot_index < len - 1) 
  	return 1;
  return 0;
}


//---------------------------------------------------------------------------------------------------------------------------


char* replace_space_with_underscore(char* str) {
  char* modified_str = malloc(strlen(str) + 1);  // Allocate memory for the modified string
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      modified_str[i] = '_';
    } else {
      modified_str[i] = str[i];
    }
  }
  modified_str[strlen(str)] = '\0';  // Add null terminator
  return modified_str;
}


//---------------------------------------------------------------------------------------------------------------------------


int search_data(int id,char *addr,char *search) {
	
		
    FILE *fp = fopen(addr, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return (int) NULL;
    }
    
    char *word = malloc(1000);
    int i=0;
    while (fscanf(fp, " %999s", word) == 1) {
    	if(i%7==id)
    	{
			if(strcmp(word,search)==0)
			{
				free(word);
    			fclose(fp);
    			return i/7+1;
			}
        }
        i++;
    }

    free(word);
    fclose(fp);
    return 0;
}


//---------------------------------------------------------------------------------------------------------------------------


char* get_line(int line_num,char *addr)
{
	FILE *fp = fopen(addr, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    char *line =malloc(1000);
    int i=0;
    while (fgets(line, sizeof(line)*1000, fp) != NULL) {
    	if(i+1==line_num)
    	{
    		fclose(fp);
        	return line;
        }
        i++;
    }
    return NULL;
}


//---------------------------------------------------------------------------------------------------------------------------


char* line_to_word(int id,char *line)
{
	char *token = strtok(line, " ");
	int i=0;
    while (token != NULL) {
        if(i==id)
        	return token;
        i++;
        token = strtok(NULL, " ");
    }
}