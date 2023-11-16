#include "shell.h"

/**
 * const_memset - Fills the memory with a constant byte
 * @mem: Pointer to the memory area
 * @byte: Byte to fill *memory with
 * @size: Amount of bytes to be filled
 *
 * Return: Returns a pointer to the memory area
 */
char *const_memset(char *mem, char byte, unsigned int size)
{
    unsigned int i;

    for (i = 0; i < size; i++)
        mem[i] = byte;
    return (mem);
}

/**
 * fsarray - Frees a string array
 * @str_array: A string array
 */
void frsarray(char **str_array)
{
    char **temp = str_array;

    if (!str_array)
        return;
    while (*str_array)
        free(*str_array++);
    free(temp);
}

/**
 * custom_realloc - Reallocates a block of memory
 * @ptr: Pointer to the previously malloc'ated block
 * @old_size: Byte size of the previous block
 * @new_size: Byte size of the new block
 *
 * Return: Returns a pointer to the old block name
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;

    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    if (new_size == old_size)
        return (ptr);

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);

    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        new_ptr[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (new_ptr);
}

