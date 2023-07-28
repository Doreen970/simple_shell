#include "shell.h"

/**
 * our_strspn- gives sub_string length
 *
 * @s1: original string
 * @s2: the sub_string
 *
 * Return: the matched substrings
 */

int our_strspn(char *s1, char *s2)
{
	int index = 0;
	int ide = 0;

	while (s1[index] != '\0')
	{
		if (d_str(s2, s1[index]) == NULL)
			break;
		ide++;
		index++;
	}
	return (ide);
}

/**
 * my_strcmp - gives comparison of one string to the other
 *
 * @s1: initial string
 *
 * @s2: preceding string
 *
 * Return: variation between the two strings
 */

int my_strcmp(char *s1, char *s2)
{
	int index = 0;

	while (s1[index])
	{
		if (s1[index] != s2[index])
		{
			break;
		}
		index++;
	}
	return (s1[index] - s2[index]);
}

/**
 * my_strcspn - cecks for uniqueness between s1 and s2
 *
 * @s1: the checked string
 * @s2: second checked string
 *
 * Return: similar index
 */

int my_strcspn(char *s1, char *s2)
{
	int len = 0, index;

	for (index = 0; s1[index] != '\0'; index++)
	{
		if (d_str(s2, s1[index]) != NULL)
			break;
		len++;
	}
	return (len);
}


/**
 * d_str - gives index of the character
 *
 * @s1: the string to check
 * @s2: another string to check
 *
 * Return: s2 memory address
 */

char *d_str(char *s1, char s2)
{
	int index;

	for (index = 0; s1[index] != s2 && s1[index]; index++)
	{
		;
	}
	if (s1[index] == s2)
	{
		return (s1 + index);
	}
	else
		return (NULL);
}

/**
 * my_strcat - join two strings
 *
 * @s1: original string
 * @s2: second string
 *
 * Return: joined strings
 */

char *my_strcat(char *s1, char *s2)
{
	char *new_str =  NULL;
	int len_1 = my_strlen(s1), len_2 = my_strlen(s2);

	new_str = malloc(sizeof(*new_str) * (len_1 + len_2 + 1));
	if (!new_str)
	{
		return (NULL);
	}
	my_strcpy(s1, new_str);
	my_strcpy(s2, new_str + len_1);
	new_str[len_1 + len_2] = '\0';

	return (new_str);
}
