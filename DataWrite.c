#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
FILE *fptr;

int Day()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return(tm.tm_mday);
}
int Month()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return((tm.tm_mon+1));
}
int Year()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return((tm.tm_year+1900));
}
int Hour()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return (tm.tm_hour);
}
int Minutes()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return (tm.tm_min);
}
int Seconds()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    return (tm.tm_sec);
}
int TimeCheck()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if(tm.tm_hour==23 && tm.tm_min>=59 && tm.tm_sec>=59)
        return(1);
    else
        return(0);
}

int main()
{
    char filepath[100]="";
    char path[]= "Data_";
    // if you want to save to specific path then use this code: char path[]= "E://Data_";
    sprintf(filepath, "%s%d-%d-%d.csv", path, Day(), Month(), Year());

    fptr= fopen(filepath, "a");

    float var[]= {11,22,33,44,55,66,77,88,99,0};
    if(TimeCheck()!=0)
    {
        fclose(fptr);
        exit(1);
    }
    else
    {
        fprintf(fptr, "%d-%d-%d,%d:%d:%d,,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", 
        Day(), Month(), Year(), Hour(), Minutes(), Seconds(),  
        var[0], var[1], var[2], var[3], var[4], var[5], var[6], var[7], var[8], var[9]);

    }
    return 0;
}
