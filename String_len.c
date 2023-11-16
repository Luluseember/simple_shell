#include "shell.h"

/**
 * custom_strlen - Returns the length of a string
 * @str: The string whose length to check
 *
 * Return: Returns an integer length of the string
 */
int custom_strlen(char *str)
{
    int length = 0;

    if (!str)
        return 0;

    while (*str++)
        length++;
    return length;
}

/**
 * custom_strcmp - Performs lexicographic comparison of two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: Negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
 */
int custom_strcmp(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    if (*str1 == *str2)
        return 0;
    else
        return (*str1 < *str2 ? -1 : 1);
}

/**
 * string_starts_with - Checks if needle starts with haystack
 * @haystack: The string to search
 * @needle: The substring to find
 *
 * Return: Returns the address of the next character of haystack or NULL
 */
char *string_starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return NULL;
    return (char *)haystack;
}

/**
 * custom_strcat - Concatenates two strings
 * @destin: The destination buffer
 * @src: The source buffer
 *
 * Return: Returns a pointer to the destination buffer
 */
char *custom_strcat(char *destin, char *src)
{
    char *result = destin;

    while (*destin)
        destin++;
    while (*src)
        *destin++ = *src++;
    *destin = *src;
    return result;
}

