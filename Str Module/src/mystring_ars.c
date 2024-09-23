#include "mystring.h"
#include <assert.h>

/*Return the length of the s string.*/
/*Assests not null char array.*/
size_t ms_length(const char s[])
{
    size_t uiLength = 0U;
    /*Check if the input string is NULL. */
    assert(s);
    /*Iterate until the end of the string is reached.*/
    while (s[uiLength])
        uiLength++;

    return uiLength;
}

/*Copy the content of src string to dest string.*/
/*Assests not null char arrays.*/
char *ms_copy(char dest[], const char src[])
{
    size_t index = 0U;
    assert(dest);
    assert(src);
    /*Iterate until the end of the source string is reached.*/
    while (src[index])
    {
        dest[index] = src[index];
        index++;
    }
    /*Add \0 to the destination string.*/
    dest[index] = '\0';
    return dest;
}

/*Copy the first n characters of src string to dest string.*/
/*Assests not null char arrays.*/
char *ms_ncopy(char dest[], const char src[], size_t n)
{
    size_t index = 0U;
    assert(dest);
    assert(src);
    /*Iterate for n time or until the end of the source string is reached.*/
    while (index != n && src[index])
    {
        dest[index] = src[index];
        index++;
    }
    /*Add \0 to the destination string.*/
    dest[index] = '\0';
    return dest;
}

/*Concatenate the content of src string to dest string.*/
/*Assests not null char arrays.*/
char *ms_concat(char dest[], const char src[])
{
    size_t index = 0U;
    size_t endOfDest;
    assert(dest);
    assert(src);
    /*Get the end of the destination string.*/
    endOfDest = ms_length(dest);
    /*Iterate until the end of the source string is reached.*/
    while (src[index])
    {
        dest[endOfDest++] = src[index++];
    }
    /*Add \0 to the destination string.*/
    dest[endOfDest] = '\0';
    return dest;
}
/*Concatenate the first n characters of src string to dest string.*/
/*Assests not null char arrays.*/
char *ms_nconcat(char dest[], const char src[], size_t n)
{
    size_t index = 0U;
    size_t endOfDest;
    assert(dest);
    assert(src);
    /*Get the end of the destination string.*/
    endOfDest = ms_length(dest);
    /*Iterate for n time or until the end of the source string is reached.*/
    while (index < n && src[index])
    {
        dest[endOfDest++] = src[index++];
    }
    dest[endOfDest] = '\0';
    return dest;
}
/*Compare two strings lexicographically.*/
/*If the strings are equal return 0,*/
/*or else return the difference in ASCII values between
    the first differing characters.*/
/*Assests not null char arrays.*/
int ms_compare(const char s1[], const char s2[])
{
    size_t index = 0U;
    assert(s1);
    assert(s2);
    while (s1[index] && s2[index])
    {
        if (s1[index] != s2[index])
        {
            return s1[index] - s2[index];
        }
        index++;
    }
    /*s1 string is longer than s2 string.*/
    if (s1[index])
    {
        return s1[index];
    }
    /*s2 string is longer than s1 string.*/
    else if (s2[index])
    {
        return -s2[index];
    }
    /*Equal strings.*/
    return 0;
}
/*Compare the first n characters of two strings lexicographically.*/
/*Assests not null char arrays.*/
int ms_ncompare(const char *s1, const char *s2, size_t n)
{
    size_t index = 0U;
    assert(s1);
    assert(s2);
    while (index < n && s1[index] && s2[index])
    {
        if (s1[index] != s2[index])
        {
            return s1[index] - s2[index];
        }
        index++;
    } /* The first n characters are equal.*/
    if (index == n)
    {
        return 0;
    } /*s1 string is longer than s2 string.*/
    else if (s1[index])
    {
        return s1[index];
    } /*s2 string is longer than s1 string.*/
    else if (s2[index])
    {
        return -s2[index];
    }
    /*Both string size are less than n*/
    /*Strings are equal within the first n characters*/
    return 0;
}
/*Search for the needle substring in the haystack string.*/
/*Assests not null char arrays.*/
char *ms_search(const char haystack[], const char needle[])
{
    size_t haystackIndex = 0U;
    size_t needleIndex = 0U, ret = 0U;
    assert(haystack);
    assert(needle);
    while (haystack[haystackIndex] && needle[needleIndex])
    {
        if (haystack[haystackIndex] == needle[needleIndex])
        { /*found matching characters*/
            if (needleIndex == 0)
            {
                /*Store the index of the first matching character.*/
                ret = haystackIndex;
            }
            needleIndex++;
        }
        else
        {
            /*Reset all indexes if the characters don't match.*/
            ret = 0U;
            needleIndex = 0U;
        }
        haystackIndex++;
    }
    if (needle[needleIndex])
    {
        /*Substring not found.*/
        return NULL;
    }
    /*Return an array of the matching substring.*/
    /*Using (char *) cast to avoid returnig a const char pointer*/
    return (char *)&haystack[ret];
}
