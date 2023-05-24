#include "shell.h"
/**
* _getenv - function to find environment variable
* @var: variable to find
* Return: pointer to string with environment variable
*/
char *_getenv(const char *var)
{
	char **env;
	size_t len = _strlen(var);

	if (var == NULL)
	{
		return (NULL);
	}
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, var, len) == 0 && (*env)[len] == '=')
		{
			return (&((*env)[len + 1]));
		}
	}
	return (NULL);
}
/**
* _strncmp - function that compares two strings
* @str1: string to compare
* @str2: second string
* @n: number of string chars to compare
* Return: 0 or differance of strings
*/
int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		if (str1[i] == '\0' || str2[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
/**
* sortenv - function to sort environment variables
* @env: variable to sort
* Return: void
*/
void sortenv(char **env)
{
	char *str;
	int i, j;
	int n = 0;

	while (env[n] != NULL)
		n++;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (_strcmp(env[j], env[j + 1]) > 0)
			{
				str = env[j];
				env[j] = env[j + 1];
				env[j + 1] = str;
			}
		}
	}
}
