#include "mystring.h"
#include <assert.h>

/*Return the length of the s string.*/
/*Assests not null pointer.*/
size_t ms_length(const char *s)
{
    const char *strEnd = s;
    /*Check if the input string is NULL. */
    assert(s);
    /*Iterate until the strEnd pointer is NULL.*/
    while (*strEnd)
        strEnd++;
    return strEnd - s;
}
/*Copy the content of src string to dest string.*/
/*Assests not null pointer.*/
char *ms_copy(char *dest, const char *src)
{
    char *startPointer = dest;
    assert(dest);
    assert(src);
    /*Iterate until the src pointer is NULL.*/
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    /*Add \0 to the destination string.*/
    *dest = '\0';
    return startPointer;
}

/*Copy the first n characters of src string to dest string.*/
/*Assests not null pointer.*/
char *ms_ncopy(char *dest, const char *src, size_t n)
{
    size_t index = 0U;
    char *startPointer = dest;
    assert(dest);
    assert(src);
    /*Iterate for n time or until the src pointer is NULL.*/
    while (index < n && *src)
    {
        *dest = *src;
        dest++;
        src++;
        index++;
    }
    /*Add \0 to the destination string.*/
    *dest = '\0';
    return startPointer;
}
/*Concatenate the content of src string to dest string.*/
/*Assests not null pointer.*/
char *ms_concat(char *dest, const char *src)
{
    char *destEnd = dest;
    assert(dest);
    assert(src);
    /*Iterate until the destEnd pointer is NULL.*/
    while (*destEnd)
    {
        destEnd++;
    }
    /*Iterate until the src pointer is NULL.*/
    while (*src)
    {
        *destEnd = *src;
        destEnd++;
        src++;
    }
    /*Add \0 to the destination string.*/
    *destEnd = '\0';
    return dest;
}
/*Concatenate the first n characters of src string to dest string.*/
/*Assests not null pointer.*/
char *ms_nconcat(char *dest, const char *src, size_t n)
{
    size_t index = 0U;
    char *destEnd = dest;
    assert(dest);
    assert(src);
    /*Get the end of the destination string.*/
    while (*destEnd)
    {
        destEnd++;
    }
    /*Iterate for n time or until the end of the src pointer is null.*/
    while (index < n && *src)
    {
        *destEnd = *src;
        destEnd++;
        src++;
    }
    *destEnd = '\0';
    return dest;
}

/*Compare two strings lexicographically.*/
/*If the strings are equal return 0,*/
/*or else return the difference in ASCII values between
    the first differing characters.*/
/*Assests not null pointer.*/
int ms_compare(const char *s1, const char *s2)
{
    assert(s1);
    assert(s2);
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    /*s1 string is longer than s2 string.*/
    if (*s1)
    {
        return *s1;
    }
    /*s2 string is longer than s1 string.*/
    else if (*s2)
    {
        return -(*s2);
    }
    /*Equal strings.*/
    return 0;
}
/*Compare the first n characters of two strings lexicographically.*/
/*Assests not null pointer.*/
int ms_ncompare(const char *s1, const char *s2, size_t n)
{
    size_t index = 0U;
    assert(s1);
    assert(s2);
    while (index < n && *s1 && *s2)
    {
        /*Non-matching characters*/
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    /* The first n characters are equal.*/
    if (index == n)
    {
        return 0;
    } /*s1 string is longer than s2 string.*/
    else if (*s1)
    {
        return *s1;
    }
    /*s2 string is longer than s1 string.*/
    else if (*s2)
    {
        return -(*s2);
    }
    /*Equal strings.*/
    return 0;
}
/*Search for the needle substring in the haystack string.*/
/*Assests non null char pointer.*/
char *ms_search(const char *haystack, const char *needle)
{
    const char *ret = NULL;
    const char *startNeedle = needle;
    assert(haystack);
    assert(needle);
    while (*haystack && *needle)
    {
        if (*haystack == *needle)
        { /*Matching characters*/
            if (needle == startNeedle)
            {
                /*Store the pointer of the first matching character.*/
                ret = haystack;
            }
            needle++;
        }
        else
        {
            /*Reset all pointers if the characters don't match.*/
            ret = NULL;
            needle = startNeedle;
        }
        haystack++;
    }
    if (*needle)
    {
        /*Substring not found.*/
        return NULL;
    }
    /*Return a pointer to the start of the matching substring.*/
    /*Using (char *) cast to avoid returnig a const char pointer*/
    return (char *)ret;
}
