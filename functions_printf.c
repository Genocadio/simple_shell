#include "main.h"
/**
 * print_char - function to print char
 * @arg: argument to printf
 * Return: number of printed charcters
 */
int print_char(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}
/**
 * print_string - function to print string
 * @arg: argument to printf
 * Return: number of printed charcters
 */
int print_string(va_list arg)
{
	int i;
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @arg: arguments to printf
 * Return: number of printed strings.
 */
int print_percent(__attribute__((unused))va_list arg)
{
	_putchar('%');
	return (1);
}
/**
 * print_int - prints an integer
 * @arg: argument to printf
 * Return: number of digits printed
 */
int print_int(va_list arg)
{
	int n;
	int dividor;
	int l;
	unsigned int num;

	n  = va_arg(arg, int);
	dividor = 1;
	l = 0;

	if (n < 0)
	{
		l += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / dividor > 9; )
		dividor *= 10;

	for (; dividor != 0; )
	{
		l += _putchar('0' + num / dividor);
		num %= dividor;
		dividor /= 10;
	}
	return (l);
}
