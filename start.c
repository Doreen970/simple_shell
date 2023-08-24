#include "shell.h"

/**
 * start - starts running our code.
 * @recent_command: checks immediate token used
 * @type_command: token parsed
 *
 * Return: nothing
 */
void start(char **recent_command, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
		{
			do_cmd(recent_command, type_command);
		}
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		do_cmd(recent_command, type_command);
}
