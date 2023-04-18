#include <stdlib.h>
#include "cmdgen.h"
#include <stdio.h>
#include <string.h>

void check_q_c(char *prompt, int *qu_clear)
{
	if (prompt == "clear")
	{
		*qu_clear = 1;
	}
	else if (prompt == "quit")
	{
		*qu_clear = 2;
	}
	else
	{
		*qu_clear = 0;
	}
}
int main(void)
{
	char *prompt;
	char *api;
	int qu_clear;

	prompt = malloc(sizeof(char) * 2048);

	if (prompt != NULL)
	{
		prompt = malloc(sizeof(char) * 2048);
		while (1)
		{
			printf("\U0001F916>");
			fgets(prompt, 2048, stdin);
			prompt[strlen(prompt) - 1] = '\0';
			check_q_c(prompt, &qu_clear);
			switch(qu_clear)
			{
				case 0:
					api = handle_api_key(stdout);
					check_conn(stdout);
					_connect(stdout, prompt, api);
					break;
				case 1:
					system("clear");
					break;
				case 2:
					exit(0);
					break;
				default:
					api = handle_api_key(stdout);
					check_conn(stdout);
					_connect(stdout, prompt, api);
					break;
			}
		}	
		free(prompt);
	}
	return (0);
}


