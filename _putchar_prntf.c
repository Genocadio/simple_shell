#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the charcters to the output
 * @c: the charcter to print
 * Return: 1 when success
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
