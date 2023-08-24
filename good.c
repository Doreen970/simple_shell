#include "shell.h"

/**
 * _strlen - finds string length
 *
 * @str: string to be checked
 *
 * Return: length of string
 */

int my_strlen(char *str)
{
	int str_len;

	if (str == NULL)
	{
		return (0);
	}
	str_len = 0;
	while (str[str_len])
	{
		str_len++;
	}

	return (str_len);
}


/**
 * no_nl - gets rid of new line
 * @str: string to be checked
 *
 * Return: nothing
 */

void no_nl(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			break;
		index++;
	}
	str[index] = '\0';
}


/**
 * tokenizer - breaks down commands into string portions
 *
 * @cmd: string to be broken down
 *
 * @delim: character to divide with
 *
 * Return: broken string
 */

char **tokenizer(char *cmd, char *delim)
{
	int num = 0;
	char **my_str = NULL, *toks = NULL, *pt = NULL;

	toks = d_strtok(cmd, delim, &pt);

	while (toks != NULL)
	{
		my_str = my_realloc(my_str, sizeof(*my_str) * num, sizeof(*my_str) * (num + 1));
		my_str[num] = toks;
		toks = d_strtok(NULL, delim, &pt);
		num++;
	}

	my_str = my_realloc(my_str, sizeof(*my_str) * num, sizeof(*my_str) * (num + 1));
	my_str[num] = NULL;

	return (my_str);
}

/**
 * _strcpy - creates copy of a string
 *
 * @s1: original place of the string
 * @s2: new string destination
 *
 * Return: void
 */

void my_strcpy(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index]; index++)
	{
		s2[index] = s1[index];
	}
	s2[index] = '\0';
}

/**
 * _write - prints results to standard output
 *
 * @str: the output
 * @stm: place to print
 *
 * Return: void
 */

void _write(char *str, int stm)
{
	int index;

	for (index = 0; str[index]; index++)
	{
		write(stm, &str[index], 1);
	}
}
