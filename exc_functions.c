#include "shell.h"

/**
 * start_fork - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int start_fork(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (my_execvp(args[0], args) == -1)
			_printf("error in start_fork: child process");
		exit(1);
	}
	else if (pid < 0)
		_printf("error in start_fork: forking");
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
/**
 * exct- function that execute passed commands
 * @args: commands passed
 * Return: -1  on success
 */
int exct(char **args)
{
	if (args[0] == NULL)
		return (-1);

	if (args[0][0] == '#')
		return (-1);

	if (is_absolute_path(args[0]))
	{
		if (access(args[0], F_OK) == 0)
		{
			return (start_fork(args));
		}

		_printf("%s: command not found\n", args[0]);
		return (-1);
	}

	if (is_builtin(args[0]))
		return (execute_builtin(args));

	if (is_command_in_path(args[0]))
		return (start_fork(args));

	_printf("%s: command not found\n", args[0]);
	return (-1);
}

/**
 * construct_path - function that constructs path to a command
 * @path_token: pointer ro path where command is located
 * @command: pointer to name of command
 * Return: pointer to path of command
 */
char *construct_path(const char *path_token, const char *command)
{
	size_t path_token_len = _strlen(path_token);
	size_t command_len = _strlen(command);
	char *resolved_path = malloc(path_token_len + command_len + 2);

	if (resolved_path == NULL)
	{
		perror("error in construct_path: malloc");
		return (NULL);
	}

	_strcpy(resolved_path, path_token);
	_strcat(resolved_path, "/");
	_strcat(resolved_path, command);

	return (resolved_path);
}
/**
 * my_execvp - implementetion of execvp function
 * @command: pointer to command to be executed
 * @args: arguments to command
 * Return: 1 if success else -1
 */
int my_execvp(const char *command, char *const args[])
{
	if (access(command, F_OK) == 0)
	{
		return ((execve(command, args, NULL) != -1) ? 0 : -1);
	}
	char *path = _getenv("PATH");

	if (path == NULL)
	{
		return (-1);
	}
	char *path_env = _strdup(path);

	if (path_env == NULL)
		return (-1);
	char *path_token = strtok(path_env, ":");

	while (path_token != NULL)
	{
		char *resolved_path = construct_path(path_token, command);

		if (resolved_path == NULL)
		{
			free(path_env);
			return (-1);
		}
		if (execve(resolved_path, args, NULL) != -1)
		{
			free(path_env);
			free(resolved_path);
			return (0);
		}
		free(resolved_path);
		path_token = strtok(NULL, ":");
	}
	perror(command);
	free(path_env);
	return (-1);
}
