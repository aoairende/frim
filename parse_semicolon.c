#include "main.h"

/**
 * starts_with_semicolon - checks if string starts with ';'
 * @str: pointer to string to check
 * Return: 1 if true, 0 otherwise
*/
int starts_with_semicolon(char *str)
{
	int valid_char_found = 0;

	while (*str != '\0')
	{
		if (*str == ';' && !valid_char_found)
			return (1);
		if (*str != ' ' && *str != '\n')
			return (0);
		str++;
	}
	return (0);
}

/**
 * has_consecutive_semicolon - checks if string has consecutive ';'
 * @str: pointer to string to check
 * Return: 1 if true, 0 otherwise
*/
int has_consecutive_semicolon(char *str)
{
	int semicolon_exist = 0;

	while (*str != '\0')
	{
		if (*str == ';')
		{
			if (semicolon_exist)
				return (1);
			semicolon_exist = 1;
		}
		else
		{
			if (*str != ' ')
				semicolon_exist = 0;
		}
		str++;
	}
	return (0);
}

/**
 * parse_semicolon - tokenize string by ';'
 * @str: pointer to string to tokenize
 * @head: pointer to linked list
 * Return: pointer to tokenized string
*/
char **parse_semicolon(char *str, list_t *head)
{

	if (str == NULL)
		return (NULL);

	if (starts_with_semicolon(str) || has_consecutive_semicolon(str))
		return (NULL);

	return (str_into_tokens(str, ';', head));
}
