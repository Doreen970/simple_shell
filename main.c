#include "shell.h"


	int status = 0;
	char **commands = NULL;
	char *line = NULL;
	char *my_shell = NULL;

/**
 * main - entry point of shell
 *
 * @argc: number of arguments
 * @argv: string of arguments
 *
 * Return: 0 on success
 */

int main(int argc __attribute__((unused)), char **argv)
{
	size_t buff_size = 0;
	char **cmd_rcv = NULL;
	int index;
	int new_cmd = 0;

	signal(SIGINT, ctrl_c);
	my_shell = argv[0];
	while (1)
	{
		no_talk();
		_write("$", STDOUT_FILENO);
		if (getline(&line, &buff_size, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			no_nl(line);
			no_cmt(line);
			commands = tokenizer(line, ";");

		for (index = 0; commands[index] != NULL; index++)
		{
			cmd_rcv = tokenizer(commands[index], " ");
			if (cmd_rcv[0] == NULL)
			{
				free(cmd_rcv);
				break;
			}
			new_cmd = give_cmd(cmd_rcv[0]);

			start(cmd_rcv, new_cmd);
			free(cmd_rcv);
		}
		free(commands);
	}
	free(line);

	return (status);
}
