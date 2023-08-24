#include "shell.h"

/**
 * give_cmd - determines command type
 * @cmd: command entered.
 *
 * Return: represents command type
 * Description - EXTERNAL_COMMAND (1) commands given with their full path.
 *		 INTERNAL_COMMAND (2) simple commands like builtin commands.
 *		 PATH_COMMAND (3) commands found in path
 *		 INVALID_COMMAND (-1) shows invalid commands
 */

int give_cmd(char *cmd)
{
	char *int_cmd[] = {"env", "exit", NULL};
	char *path = NULL;
	int index;

	for (index = 0; cmd[index] != '\0'; index++)
	{
		if (cmd[index] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (index = 0; int_cmd[index] != NULL; index++)
	{
		if (my_strcmp(cmd, int_cmd[index]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = path_check(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
 * do_cmd - function that performs the command given
 * @cmd_toks: command after tokenization
 * @cmd_typ: type of the command
 *
 * Return: void
 */

void do_cmd(char **cmd_toks, int cmd_typ)
{
	void (*func)(char **command);

	if (cmd_typ == EXTERNAL_COMMAND)
	{
		if (execve(cmd_toks[0], cmd_toks, NULL) == -1)
		{
			perror(find_environ("PWD"));
			exit(2);
		}
	}
	if (cmd_typ == PATH_COMMAND)
	{
		if (execve(path_check(cmd_toks[0]), cmd_toks, NULL) == -1)
		{
			perror(find_environ("PWD"));
			exit(2);
		}
	}
	if (cmd_typ == INTERNAL_COMMAND)
	{
		func = get_func(cmd_toks[0]);
		func(cmd_toks);
	}
	if (cmd_typ == INVALID_COMMAND)
	{
		_write(my_shell, STDERR_FILENO);
		_write(": 1: ", STDERR_FILENO);
		_write(cmd_toks[0], STDERR_FILENO);
		_write(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * path_check - checks if a command is in the PATH.
 * @cmd: command to be performed
 *
 * Return: command path
 */

char *path_check(char *cmd)
{
	char *tea, *tea2, *path_cpy;
	char **zone = NULL;
	char *path = find_environ("PATH");
	int index;

	if (path == NULL || my_strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (my_strlen(path) + 1));
	my_strcpy(path, path_cpy);
	zone = tokenizer(path_cpy, ":");

	for (index = 0; zone[index] != NULL; index++)
	{
		tea2 = my_strcat(zone[index], "/");
		tea = my_strcat(tea2, cmd);
		if (access(tea, F_OK) == 0)
		{
			free(tea2);
			free(zone);
			free(path_cpy);
			return (tea);
		}
		free(tea);
		free(tea2);
	}
	free(path_cpy);
	free(zone);
	return (NULL);
}

/**
 * get_func - finds a function according to command given
 * @cmd: string to be checked
 *
 * Return: the function pointer
 */

void (*get_func(char *cmd))(char **)
{
	int index;
	funs_area tracking[] = {
		{"env", my_env}, {"exit", out}
	};

	for (index = 0; index < 2; index++)
	{
		if (my_strcmp(cmd, tracking[index].cmd) == 0)
			return (tracking[index].func);
	}

	return (NULL);
}

/**
 * find_environ - finds value of environment variable
 * @pt: environment variable name
 *
 * Return: the value of the variable
 */


char *find_environ(char *pt)
{
	char *twin_ptr;
	char **my_environ_var;
	char *nameCopy;

	for (my_environ_var = environ; *my_environ_var != NULL; my_environ_var++)
	{
		for (twin_ptr = *my_environ_var, nameCopy = pt;
		     *twin_ptr == *nameCopy; twin_ptr++, nameCopy++)
		{
			if (*twin_ptr == '=')
				break;
		}
		if ((*twin_ptr == '=') && (*nameCopy == '\0'))
			return (twin_ptr + 1);
	}

	return (NULL);
}
