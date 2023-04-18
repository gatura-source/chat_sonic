#include <stdlib.h>
#include <string.h>
#include "cmdgen.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <jansson.h>
/**
 * check_conn - uses sys's ping to check for internet connection
 *
 * Return: 0 on success, else 1
 */

int check_conn(FILE *stream)
{
	int success;

	//fprintf(stream, "\n-+++ Checking for Connection -+++\n\n");
	success = system("ping -c1 -w1 1.1.1.1 > /dev/null 2>&1");
	if (success == 0)
	{
		//fprintf(stream, "\nSuccess\n");
		return (success);
	}
	else
	{

		return (success);
		exit(1);
	}
}
	

const char *_connect(FILE *stream, char *prompt, char *api)
{
	char buffer[2048];
	const char *message;
	char *m_essage;
	FILE *output;
	int success;
	long len;
	json_t *root;
	json_error_t error;


	sprintf(buffer, "curl -s --request POST --url %s --header 'X-API-KEY: %s' --header 'accept: %s' --header 'content-type: %s' --data '{\"enable_google_results\": \"true\", \"enable_memory\": false, \"input_text\": \"%s\"}'> output.json", URL, api, accept, content, prompt);

	success = system(buffer);
	if (success == 0)
	{
		output = fopen("output.json", "r");
		if (output == NULL)
		{
			fprintf(stream, "Something went wrong, try again\n");
			return (NULL);
		}
		else
		{
			fseek(output, 0, SEEK_END);
			len = ftell(output);
			rewind(output);
			m_essage = malloc((len+1) * sizeof(char));
			fread(m_essage, len, 1, output);
			m_essage[len] = '\0';

			root = json_loads(m_essage, 0, &error);
			if (!root)
			{
				fprintf(stream, "Error fetching data\n");
				return (NULL);
			}
			else
			{
				message = malloc(2048 * sizeof(char));
				message = json_string_value(json_object_get(root, "message"));
				fprintf(stream,"%s\n", message);
				return (message);
			}
			fclose(output);
			free(m_essage);
		}
	}	
}
