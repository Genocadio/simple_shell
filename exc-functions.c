#include "shell.h"
/**
 * is_absolute_path - function that checks if path is absolute path
 * @path: path to check
 * Return: absolute path
 */
int is_absolute_path(const char *path)
{
	return (path[0] == '/');
}

/**
 * is_builtin - function that check if command is builtin
 * @command: command to check
 * Return: 1 if true or else 0
 */

int is_builtin(const char *command)
{
	BuiltinFunction builtin_func_list[] = {
		{"cd", &builtin_cd},
		{"env", &builtin_env},
		{"exit", &builtin_exit}
		};
	size_t num = sizeof(builtin_func_list) / sizeof(BuiltinFunction);

	for (size_t i = 0; i < num; i++)
	{
		if (_strcmp(command, builtin_func_list[i].name) == 0)
			return (1);
	}
	return (0);
}
/**
 * execute_builtin - function to execute a buildin command
 * @args: command to execute
 * Return: function executed or -1
 */
int execute_builtin(char **args)
{

	BuiltinFunction builtin_func_list[] = {
		{"cd", &builtin_cd},
		{"env", &builtin_env},
		{"exit", &builtin_exit}
		};
	size_t num = sizeof(builtin_func_list) / sizeof(BuiltinFunction);

	for (size_t i = 0; i < num; i++)
	{
		if (_strcmp(args[0], builtin_func_list[i].name) == 0)
			return ((*(builtin_func_list[i].func))(args));
	}
	return (-1);
}
/**
 * is_command_in_path - function that check if command is in path
 * @command: command to check
 * Return: 0 on success or else -1
 */
int is_command_in_path(const char *command)
{
	char *path = _getenv("PATH");

	if (path != NULL)
	{
		char *path_env = _strdup(path);

		if (path_env == NULL)
		{
			perror("error in is_command_in_path: strdup");
			return (-1);
		}

		char *path_token = strtok(path_env, ":");

		while (path_token != NULL)
		{
			char *resolved_path = construct_path(path_token, command);

			if (resolved_path == NULL)
			{
				free(path_env);
				return (-1);
			}
			if (access(resolved_path, F_OK) == 0)
			{
				free(resolved_path);
				free(path_env);
				return (1);
			}
			free(resolved_path);
			path_token = strtok(NULL, ":");
		}
		free(path_env);
	}
	return (0);
}
