#include "shell.h"
#include "Prints.h"

/**
 * interactive_mode - Checks if the shell is in interactive mode
 * @data: Pointer to the struct containing shell information
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive_mode(info_t *data)
{
	return (isatty(STDIN_FILENO) && data->readfd <= 2);
}

/**
 * is_separ- Checks if a character is a separator
 * @ch: Character to check
 * @separ: String containing separators
 *
 * Return: 1 if true, 0 if false
 */
int is_separ(char ch, char *separ)
{
	while (*separ)
	{
		if (*separ++ == ch)
			return (1);
	}
	return (0);
}

/**
 * custom_isalpha - Checks if a character is alphabetic
 * @ch: The character to check
 *
 * Return: 1 if 'character' is alphabetic, 0 otherwise
 */
int custom_isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * sti - Converts a string to an integer
 * @str: The string to be converted
 *
 * Return: 0 if no numbers in the string, converted number otherwise
 */
int sti(char *str)
{
	int index, sign = 1, flag = 0, result;
	unsigned int value = 0;

	for (index = 0; str[index] != '\0' && flag != 2; index++)
	{
		if (str[index] == '-')
			sign *= -1;

		if (str[index] >= '0' && str[index] <= '9')
		{
			flag = 1;
			value *= 10;
			value += (str[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -value;
	else
		result = value;

	return (result);
}

