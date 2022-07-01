#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char basic[27] = "abcdefghijklmnopqrstuvwxyz\0";
char capital[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
char numbers[11] = "1234567890\0";
char special_chars[14] = "!@#$%^&*()-_+\0";

int ar_size;


void pass_gen(unsigned long length, char* options)
{

    if(strcmp(options, "-c" ) == 0)
    {
        strcat(basic, capital);
        ar_size = strlen(basic);
        basic[ar_size] = '\0';
    }
    else if(strcmp(options, "-cn" ) == 0)
    {
        strcat(basic, capital);
        strcat(basic, numbers);
        ar_size = strlen(basic);
        basic[ar_size] = '\0';
    }
    else if(strcmp(options, "-n" ) == 0)
    {
        strcat(basic, numbers);
        ar_size = strlen(basic);
        basic[ar_size] = '\0';
    }
    else if(strcmp(options, "-a" ) == 0)
    {
        strcat(basic, capital);
        strcat(basic, numbers);
        strcat(basic, special_chars);
        ar_size = strlen(basic);
        basic[ar_size] = '\0';
    }

    else if(strcmp(options, "-s" ) == 0)
    {
        strcat(basic, special_chars);
        ar_size = strlen(basic);
        basic[ar_size] = '\0';
    }

    for (int i = 0; i < length; i++)
    {
        int rnd = rand() % ar_size; 

        printf("%c", basic[rnd]);
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    srand(time(0));
    
    char *pEnd; 
    unsigned long len = strtol(argv[1], &pEnd, 0);
    
    if(len > 256)
    {
        puts("password needs to be less than 256");
        return -1;
    }

    if(len < 1)
    {
        puts("you didn't enter a number or entered a number thats less than 1");
    }

    if(argc == 1) 
    {
        puts("usage: passgen [length] [options] options: {-c, -cn, -n}");
    }

    if(argc >= 2)
    {
        char *opts = argv[2];
        pass_gen(len, opts);
    }

    return 0;
}
