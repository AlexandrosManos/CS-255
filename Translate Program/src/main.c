#include <stdio.h>
#include <stdlib.h>

#define rows 73
#define col 3

/*Global viriable, the map*/
char map[rows][col];

void map_init();
void simple(int c);
void diphthongs(int c);
int find_state(int c);

enum states
{
    simple_state = 0,
    diphthongs_state = 1
};

int main()
{
    int c;

    map_init();
    c = getchar();
    while (c != EOF)
    {
        if (find_state(c) == simple_state)
        {
            /*Simple characters*/
            simple(c);
        }
        else /*potential for dipthong character */
            diphthongs(c);
        c = getchar();
    }
    return 0;
}

void map_init()
{
    /*Initialize the map array based on iso 8859-7*/
    int i, j;
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < rows; j++)
        {
            map[j][i] = '\0';
        }
    }
    /*Quotes*/
    for (i = 0; i <= 10; i++)
    {
        if (i == 1 || i == 5 || i == 7)
        {
            continue;
        }
        map[i][0] = '\'';
    }
    for (i = 38; i <= 41; i++)
    {
        map[i][1] = '\'';
    }
    map[70][1] = '\'';
    map[71][1] = '\'';
    map[72][1] = '\'';

    map[0][1] = 'A';
    map[2][1] = 'E';
    map[3][1] = 'H';
    map[4][1] = 'I';
    map[6][1] = 'O';
    map[8][1] = 'Y';
    map[9][1] = 'W';

    map[38][0] = 'a';
    map[39][0] = 'e';
    map[40][0] = 'h';
    map[41][0] = 'i';
    map[70][0] = 'o';
    map[71][0] = 'u';
    map[72][0] = 'w';

    /*letter sound*/
    map[68][0] = 'i';
    map[68][1] = '\"';

    map[69][0] = 'u';
    map[69][1] = '\"';

    map[10][0] = 'i';
    map[10][1] = '\"';
    map[10][2] = '\'';

    map[42][0] = 'u';
    map[42][1] = '\"';
    map[42][2] = '\'';
    /* simple */
    /*Upper Case*/
    map[11][0] = 'A';
    map[12][0] = 'V';
    map[13][0] = 'G';
    map[14][0] = 'D';
    map[15][0] = 'E';
    map[16][0] = 'Z';
    map[17][0] = 'H';
    map[18][0] = '8';
    map[19][0] = 'I';
    map[20][0] = 'K';
    map[21][0] = 'L';
    map[22][0] = 'M';
    map[23][0] = 'N';
    map[24][0] = 'K';
    map[24][1] = 'S';
    map[25][0] = 'O';
    map[26][0] = 'P';
    map[27][0] = 'R';
    map[29][0] = 'S';
    map[30][0] = 'T';
    map[31][0] = 'Y';
    map[32][0] = 'F';
    map[33][0] = 'X';
    map[34][0] = 'P';
    map[34][1] = 'S';
    map[35][0] = 'W';
    /*lowercase*/
    map[43][0] = 'a';
    map[44][0] = 'v';
    map[45][0] = 'g';
    map[46][0] = 'd';
    map[47][0] = 'e';
    map[48][0] = 'z';
    map[49][0] = 'h';
    map[50][0] = '8';
    map[51][0] = 'i';
    map[52][0] = 'k';
    map[53][0] = 'l';
    map[54][0] = 'm';
    map[55][0] = 'n';
    map[56][0] = 'k';
    map[56][1] = 's';
    map[57][0] = 'o';
    map[58][0] = 'p';
    map[59][0] = 'r';
    map[60][0] = 's';
    map[61][0] = 's';
    map[62][0] = 't';
    map[63][0] = 'u';
    map[64][0] = 'f';
    map[65][0] = 'x';
    map[66][0] = 'p';
    map[66][1] = 's';
    map[67][0] = 'w';
}

void simple(int c)
{
    if (c < 182)
    {
        /*no conversion needs to be done */
        putchar(c);
    }
    else
    {
        int k, i;
        char out;
        k = 0;
        i = c % 182;
        out = map[i][k];
        /*Check for quotes or letter sounds*/
        while (out != '\0' && k < 3)
        {
            putchar(out);
            k++;
            out = map[i][k];
        }
    }
}

void diphthongs(int c)
{
    int next = getchar();
    if (next == EOF)
    { /*there is no next character, print the c character*/
        simple(c);
    }
    else if (next == 212 || next == 244)
    { /*next character is T or t*/
        if (c == 205)
        { /*c == N*/
            putchar('D');
        }
        else if (c == 237)
        { /*c == n*/
            putchar('d');
        }
        else
        { /*case were c == M or m and next == P or p*/
            simple(c);
            simple(next);
        }
    }
    else if (next == 208 || next == 240)
    { /*next character is P or p*/
        if (c == 204)
        { /*c == M*/
            putchar('B');
        }
        else if (c == 236)
        { /*c == m*/
            putchar('b');
        }
        else
        { /*case were c == N or n and next == T or t*/
            simple(c);
            simple(next);
        }
    }
    else
    {
        simple(c);
        if (find_state(next) == diphthongs_state)
        {
            diphthongs(next);
        }
        else
        {
            simple(next);
        }
    }
}

int find_state(int c)
{
    /*c == N or c == n or c == M or c == m*/
    /*dipthongs potential*/
    if (c == 205 || c == 237 || c == 204 || c == 236)
    {
        return 1;
    }
    else
        return 0;
}
