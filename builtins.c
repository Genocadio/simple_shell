#include "shell.h"

/**
 * builtin_cd - changes the working dir of the current shell executon env
 * @args: target directory
 * Return: 1 one success, 0 otherwise.
 */
int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		_printf("expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in builtin_cd.c: changing dir\n");
		}
	}
	return (-1);
}
/**
 * builtin_env - function that prints enviroment variables
 * @args: arguments
 * Return: -1
 */
int builtin_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (-1);
}
/**
 * builtin_exit - exit a process
 * @args: arguments
 * Return: 0 if success
 */
int builtin_exit(char **args)
{
	if (args[1])
	{
		return (_atoi(args[1]));
	}
	else
	{
		return (0);
	}
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
