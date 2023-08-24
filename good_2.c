#include "shell.h"


/**
 * d_strtok - current strto
 *
 * @string: the item to be broken 
 * @delim: determinant for subdivision
 * @save_ptr: pointer containing delimiter
 *
 * Return: next token
 */

char *d_strtok(char *string, char *delim, char **save_ptr)
{
	char *fin;

	if (string == NULL)
	{
		string = *save_ptr;
	}

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}
	string += our_strspn(string, delim);

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	fin = string + my_strcspn(string, delim);

	if (*fin == '\0')
	{
		*save_ptr = fin;
		return (string);
	}

	*fin = '\0';
	*save_ptr = fin + 1;

	return (string);
}

/**
 * my_atoi - converts char to int
 *
 * @s: string to check
 *
 * Return: an integer string
 */

int my_atoi(char *s)
{
	size_t num = 0;

	do {
		if (*s == '-')
		{
			return (-1);
		}
		else if ((*s < '0' || *s > '9') && *s != '\0')
		{
			return (-1);
		}
		else if (*s >= '0'  && *s <= '9')
		{
			num = (num * 10) + (*s - '0');
		}
		else if (num > 0)
		{
			break;
		}
	} while (*s++);

	return (num);
}

/**
 * my_realloc - reallocates  memory 
 *
 * @ptr: pointer to allocated memory
 * @prv_size: original ponter size
 * @now_size: new size
 *
 * Return: pointer to address of a reallocated memory 
 */

void *my_realloc(void *ptr, size_t prv_size, size_t now_size)
{
	void *tea;
	size_t index;

	if (ptr == NULL)
	{
		tea = malloc(now_size);
		return (tea);
	}
	else if (now_size == prv_size)
	{
		return (ptr);
	}
	else if (now_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		tea = malloc(now_size);
		if (tea != NULL)
		{
			for (index = 0; index < min(prv_size, now_size); index++)
				*((char *)tea + index) = *((char *)ptr + index);
			free(ptr);

			return (tea);
		}
		else
			return (NULL);

	}
}

/**
 * ctrl_c - controls the sign -> CTRL-C
 *
 * @signum: the signal
 *
 * Return: nothing
 */

void ctrl_c(int signum)
{
	if (signum == SIGINT)
	{
		_write("\n:) ", STDIN_FILENO);
	}
}

/**
 * no_cmt - avoids inputs after '#'
 *
 * @input: the input
 *
 * Return: void
 */

void no_cmt(char *input)
{
	int index = 0;

	if (input[index] == '#')
	{
		input[index] = '\0';
	}
	while (input[index])
	{
		if (input[index] == '#' && input[index - 1] == ' ')
		{
			break;
		}
		index++;
	}
	input[index] = '\0';
}
