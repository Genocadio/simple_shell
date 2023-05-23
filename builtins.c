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
 * builtin_setenv - function to set environment variable
 * @args: variable to set
 * Return: -1
 */
int builtin_setenv(char **args)
{
	int ret;

	if (args[1] == NULL || args[2] == NULL)
	{
		_printf("setenv: Invalid arguments to setenv\n");
		return (-1);
	}
	ret = setenv(args[1], args[2], 1);
	if (ret != 0)
	{
		_printf("setenv: Failed to set environment variable\n");
	}

	return (-1);
}

/**
 * builtin_unsetenv - function to unset environment variable
 * @args: variable to unset
 * Return: -1
 */
int builtin_unsetenv(char **args)
{
	int ret;

	if (args[1] == NULL)
	{
		_printf("unsetenv: Missing variable name\n");
		return (-1);
	}
	ret = unsetenv(args[1]);
	if (ret != 0 && args[1] != NULL)
	{
		_printf("unsetenv: Failed to unset environment variable\n");
	}

	return (-1);
}
