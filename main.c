#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include "cmdgen.h"

/**
 * main - Entry point
 *@argc: args counter
 *@argv: args vector
 *
 *Return: 0 on success, 1 otherwise
 */

/**
 * Author:: Bedan Gatura
 */

/* Version 0.0.1*/

const char *cmdgen_ver = "cmd-gen 0.0.1";

/****************/

/**Email**/
const char *cmd_gen_bug_address = "<gatura007@protonmail.com>";

/****************/


/**Documentation**/
const char Doc[] = "Program generates bash commands using GPT-4 by passing prompts supplied by user\n";

/*******************/

/*structure used by main to communicate with parse_opt**/
struct arguments
{
	char *args[1];	 /**arg 1 */
	int verbose; 	/**-v flag**/
	int exec;	/**-e flag **/
	int gen;	/**-g flag **/
	int u;		/**-u flag**/
	char *outfile;	/**args for -o**/
	int prompt; 	/**args for -p**/
};
/*******************************************************/

/**
 * OPTIONS Field 1 in argp
 * Order of fields: {NAME, KEY, ARG, FLAGS, DOC}
 */

static struct argp_option options[] = 
{
	{"verbose", 'v', 0, 0, "Produce verbose output"},
	{"prompt", 'p', 0, 0, "Used to generate bash commands using GPT-4"},
	{"FILE_NAME", 'o', "OUTFILE", '0', "FILE_NAME for bash script"},
	{"GENERATE", 'g', 0, 0, "Generate bash code"},
	{"EXECUTE", 'e', 0, 0, "Execute commands generated"},
	{"UTILITY", 'u', 0, 0, "Outputs the whole GPT-4 generated text and does nothing"},
	{0}
};

/*******************************************************/

/**
 * PARSER. Field 2 in argp
 * Order of parameters: KEY, ARG, STATE.
 */

/**Handles input errors**/
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;

	switch (key)
	{
		case 'v':
			arguments->verbose = 1;
			break;
		case 'o':
			arguments->outfile = arg;
			break;
		case 'p':
			arguments->prompt = 1;
			break;
		case 'u':
			arguments->u = 1;
			break;
		case 'e':
			arguments->exec = 1;
			break;
		case 'g':
			arguments->gen = 1;
			break;
		case ARGP_KEY_ARG:
			arguments->args[state->arg_num] = arg;
			break;
		case ARGP_KEY_END:
			if (state->arg_num != 1)
			{
				argp_usage(state);
			}
			break;
		default:
			return (ARGP_ERR_UNKNOWN);
	}

	return (0);
}

static struct argp argp =
{
	options,
	parse_opt,
	"PROMPT",
	Doc,
	0,
	0,
	0
};
 int main(int argc, char **argv)
{
	struct arguments arguments;
	FILE *outstream;
	char *api;
	int ping;
	char *response;

	arguments.outfile = NULL;
	arguments.verbose = 0;
	arguments.prompt = 0;
	arguments.exec = 0;
	arguments.gen = 0;
	arguments.u = 0;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	char inf_o[] = "Command-line utility for ChatGPT\nSpecifically Built to generate Code directly in the working space\n\n";

	if (arguments.outfile)
	{
		outstream = fopen(arguments.outfile, "w");
	}
	else
	{
		outstream = stdout;
	}
	
	if (arguments.prompt)
	{
		fprintf(outstream, "%s", inf_o);
		fprintf(outstream, "-+++ Initializing +++...\n");
		fprintf(outstream, "-+++ Prompt passed:: %s- +++\n", arguments.args[0]);
			
		api = handle_api_key(outstream);
		ping = check_conn(outstream);
		_connect(outstream, arguments.args[0], api);
	}
	return (0);

}
