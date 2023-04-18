#include <stdio.h>
#include <stdlib.h>
#include "cmdgen.h"
/**
 * handle_api_key - checks if API_KEY is set
 * @stream: output terminal (stderr, stdout)
 * Return: 0 on success, 1 otherwise
 */

#define TIP "SET YOUR API KEY PLEASE AS SHOWN BELOW"
#define TIP_2 "export API_KEY=<YOUR API_KEY>"
#define SUCCESS "API KEY SET SUCCESSFULLY"
char *handle_api_key(FILE *stream)
{
	char *USER_API_KEY;

	//fprintf(stream, "\n -+++ Checking for API KEY +++-\n\n");
	USER_API_KEY = getenv("API_KEY");
	if (USER_API_KEY == NULL)
	{
		fprintf(stream, "API KEY NOT SET\n\n");
		fprintf(stream, "%s\n\n%s\n\n", TIP, TIP_2);
		return (USER_API_KEY);
		exit(1);
	}
	else
	{
		//fprintf(stream, "%s\n\n", SUCCESS);
		return (USER_API_KEY);
	}
}



		
