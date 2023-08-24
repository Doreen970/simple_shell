#include "shell.h"

/**
 * no_talk - implements non_interactive mode of the shell.
 *
 * Return: void
 */
void no_talk(void)
{
	int index;
	int new_cmd = 0;
	size_t me = 0;
	char **now_cmd = NULL;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &me, stdin) != -1)
		{
			no_nl(line);
			no_cmt(line);
			commands = tokenizer(line, ";");
			for (index = 0; commands[index] != NULL; index++)
			{
				now_cmd = tokenizer(commands[index], " ");
				if (now_cmd[0] == NULL)
				{
					free(now_cmd);
					break;
				}
				new_cmd = give_cmd(now_cmd[0]);
				start(now_cmd, new_cmd);
				free(now_cmd);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
