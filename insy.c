#include "shell.h"

/**
 * out - the exit command
 *
 * @cmd_toks: command given
 *
 * Return: nothing
 */

void out(char **cmd_toks)
{
	int t = 0, cd;

	for (; cmd_toks[t] != NULL; t++)
	{
		;
	}
	if (t == 1)
	{
		free(cmd_toks), free(line), free(commands);
		exit(status);
	}
	else if (t == 2)
	{
		cd = my_atoi(cmd_toks[1]);
		if (cd == -1)
		{
			_write(my_shell, STDERR_FILENO);
			_write(": 1: exit: Illegal number: ", STDERR_FILENO);
			_write(cmd_toks[1], STDERR_FILENO);
			_write("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line), free(cmd_toks), free(commands);
			exit(cd);
		}
	}
	else
		_write("$: many arguments on exit\n", STDERR_FILENO);
}


/**
 * my_env - gives current envirinment variables
 *
 * @cmd_toks: command  passed
 *
 * Return: nothing
 */

void my_env(__attribute__((unused)) char **cmd_toks)
{
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		_write(environ[index], STDOUT_FILENO);
		_write("\n", STDOUT_FILENO);
	}
}
