#include <stdlib.h>

/*Return the length of the s string.*/
size_t ms_length(const char *s);

/*Copy the content of src string to dest string.*/
char *ms_copy(char *dest, const char *src);

/*Copy the first n characters of src string to dest string.*/
char *ms_ncopy(char *dest, const char *src, size_t n);

/*Concatenate the content of src string to dest string.*/
char *ms_concat(char *dest, const char *src);

/*Concatenate the content of src string to dest string.*/
char *ms_nconcat(char *dest, const char *src, size_t n);

/*Compare two strings lexicographically.*/
/*If the strings are equal return 0,*/
/*or else return the difference in ASCII values between
    the first differing characters.*/
int ms_compare(const char *s1, const char *s2);

/*Compare the first n characters of two strings lexicographically.*/
int ms_ncompare(const char *s1, const char *s2, size_t n);

/* Search for the needle substring in the haystack string.*/
char *ms_search(const char *haystack, const char *needle);