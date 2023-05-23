#include "shell.h"
/**
 * ctrlc- handle the ctrl signal
 * @ctr_c: ctrl c signal
 * Return: void
 */
void ctrlc(int ctr_c)
{
	(void)ctr_c;
	const char *prompt = "\nGeno_Agaba$";

	write(1, prompt, 12);
}

/**
 * main - initialize the shell in interactive or non interactive mode
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(0) != 1)
	{
		char *str;
		char **args;
		int n = -1;

		while (n == -1)
		{
			str = gtinput();
			args = toknise(str);
			n = exct(args);
			free(str);
			free(args);
			if (n >= 0)
				exit(n);
		}
	}
	else
	{
		char *str;
		char **args;
		int n = -1;
		const char *prompt = "Geno_Agaba$";

		while (n == -1)
		{
			signal(SIGINT, ctrlc);
			write(1, prompt, 11);
			str = gtinput();
			args = toknise(str);
			n = exct(args);
			free(str);
			free(args);

			if (n >= 0)

				exit(n);
		}
	}
	return (0);
}

/**
 * gtinput - read a line from stdin
 * Return: pointer to a string that holds input
 */
char *gtinput(void)
{
	char *input_str = NULL;
	size_t buffer_size = 0;
	ssize_t retn;

	retn = getline(&input_str, &buffer_size, stdin);
	if (retn == -1)
	{
		if (feof(stdin))
		{
			free(input_str);
			exit(0);
		}
		else
		{
			perror("Error in gtinput");
			exit(EXIT_FAILURE);
		}
	}
	return (input_str);
}

/**
 * toknise - split a string into multiple strings
 * @str: string to be splited
 * Return: pointer to new array
 */
char **toknise(char *str)
{
	char *token;
	int args_n;
	int buffsize = 70;
	char **args = malloc(buffsize * sizeof(char *));

	token = strtok(str, TOK_DELIM);
	args_n = 0;
	while (token != NULL)
	{
		args[args_n] = token;
		token = strtok(NULL, TOK_DELIM);
		args_n++;
	}
	args[args_n] = NULL;
	return (args);
}
/**
 * _atoi - function that conert input to integer
 * @s: charcter input
 * Return: integer value
 */
int _atoi(char *s)
{
	int sign = 1, i = 0, num = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}

	return (sign * num);
}
