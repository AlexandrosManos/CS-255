#include <stdlib.h>
#include <stdio.h>
#include "mystring.h"
#include <string.h>

int main()
{
    /*----------------Arrays-------------------------------*/
    /*
    char str1[] = "abcd", str2[] = "abcda", str3[10], str4[10];
    const char haystack[20] = "ThisIsAtest";
    const char needle[10] = "is";
    */
    /*-----------------Pointers--------------------------*/
    char str3a[10], str4a[10];
    char *str1a = "abcd", *str2a = "abce", *needle1 = "is";
    const char haystack[20] = "ThisIsAtest";
    /*--------------------Test for arrays -----------------*/
    /*
     printf("---length-----------\n");
    printf("strlen(str1) = %ld \n", strlen(str1));
    printf("strlen(str1) = %ld \n", ms_length(str1));
    printf("---string copy-----------\n");
    printf("strcpy(str3, str1) = %s\n", strcpy(str3, str1));
    printf("ms_copy(str4, str1) = %s\n", ms_copy(str4, str1));
    printf("---strcmp-----\n");
    printf("strcmp(str1, str2) = %d\n", strcmp(str1, str2));
    printf("ms_compare(str1, str2) = %d\n", ms_compare(str1, str2));
    printf("---strstr-----\n");
    printf("strstr(haystack, needle): %s\n", strstr(haystack, needle));
    printf("ms_search(haystack, needle): %s\n", ms_search(haystack, needle));
    */
    /*-------------------Test for pointers--------------------*/
    printf("---length-----------\n");
    printf("strlen(str1a) = %ld \n", strlen(str1a));
    printf("strlen(str1a) = %ld \n", ms_length(str1a));
    printf("---string copy-----------\n");
    printf("strcpy(str3a, str1a) = %s\n", strcpy(str3a, str1a));
    printf("ms_copy(str4a, str1a) = %s\n", ms_copy(str4a, str1a));
    printf("---string compare-----\n");
    printf("strcmp(str1a, str2a) = %d\n", strcmp(str1a, str2a));
    printf("ms_compare(str1a, str2a) = %d\n", ms_compare(str1a, str2a));
    printf("---string search-----\n");
    printf("strstr(haystack, needle): %s\n", strstr(haystack, needle1));
    printf("ms_search(haystack, needle): %s\n", ms_search(haystack, needle1));

    return 0;
}