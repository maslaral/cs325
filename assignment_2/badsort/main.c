#include <stdio.h>
#include <stdlib.h>
#include "badsort.h"

int main(int argc, char *argv[])
{
    int a, b;
    float num;
    
    printf("Enter a fraction for the a value: ");
    scanf("%d/%d", &a, &b);
    
    num = (float)a / (float)b;
    
    readFile("data.txt", num);
    return 0;
};
