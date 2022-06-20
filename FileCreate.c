#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
FILE *fptr;
int Dayx()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return (tm.tm_mday);
}
int Monthx()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return ((tm.tm_mon + 1));
}
int Yearx()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return ((tm.tm_year + 1900));
}

int main()
{
    char filepath[100] = "";
    char path[] = "Data_";
    // if you want to save to specific path then use this code: char path[]= "E://Data_";

    sprintf(filepath, "%s%d-%d-%d.csv", path, Dayx(), Monthx(), Yearx());
    fptr = fopen(filepath, "w");
    fprintf(fptr, "Date, Time,, var1, var2, var3, var4, var5, var6, var7, var8, var9, var10\n");
    fclose(fptr);
    return 0;
}
