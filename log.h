#ifndef LOG_INCLUDED
#define LOG_INCLUDED
#include <stdio.h>
#include <time.h>
#include <string.h>

int make_log(int userid,int productid,int activityid,char* info);
int log_time(int func_id,int userid);
void searchse(int activition,int data_id, time_t *data1,time_t *data2);
void searchue(int id);
#endif