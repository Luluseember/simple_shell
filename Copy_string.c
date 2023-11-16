#include "shell.h"

/**
 * cust_strncpy - Copies a string
 * @destin: this is the destination string to be copied to
 * @source: the source string
 * @limit: number of characters to be copied
 * Return: Returns the concatenated string
 */
char *cust_strncpy(char *destin, char *source, int limit)
{
    int src, dest;
    char *result = destin;

   src = 0;
    while (source[src] != '\0' && src < limit - 1)
    {
        destin[src] = source[src];
       src++;
    }

    if (src < limit)
    {
        dest = src;
        while (dest < limit)
        {
            destin[dest] = '\0';
           dest++;
        }
    }

    return (result);
}

/**
 * custom_strncat - Concatenates two strings
 * @first: First string
 * @second: Second string
 * @limit: number of bytes to be maximally used
 * Return: Returns the concatenated string
 */
char *custom_strncat(char *first, char *second, int limit)
{
    int one, two;
    char *result = first;

   one = 0;
    while (first[one] != '\0')
      one++;

    two = 0;
    while (second[two] != '\0' && two < limit)
    {
        first[one] = second[two];
        one++;
       two++;
    }

    if (one < limit)
        first[one] = '\0';

    return (result);
}

/**
 * custom_strchr - Locates a character in a string
 * @string: String to be parsed
 * @character: Character to look for
 * Return: Returns a pointer to the memory area of the string
 */
char *custom_strchr(char *string, char character)
{
    do
    {
        if (*string == character)
            return (string);
    } while (*string++ != '\0');

    return (NULL);
}

