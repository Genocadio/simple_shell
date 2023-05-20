#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that work like printf
 * @format: string of charcters
 * Return: number of printed charcters
 */
int _printf(const char *format, ...)
{
	selct func[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
	};
	va_list args;
	int printed_chars;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	printed_chars = selector(format, func, args);
	va_end(args);
	return (printed_chars);
}
/**
 * selector - function to select appropriate function
 * @format: is a character string
 * @func: structure with all possible functions
 * @args: arguments to printf
 * Return: number of printed characters
 */
int selector(const char *format, selct func[], va_list args)
{
	int i, j, printed_char, cnt;

	printed_char = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func[j].spc != NULL; j++)
			{
				if (format[i + 1] == func[j].spc[0])
				{
					cnt = func[j].f(args);
					if (cnt == -1)
						return (-1);
					printed_char += cnt;
					break;
				}
			}
			if (func[j].spc == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_char = printed_char + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed_char++;
		}
	}
	return (printed_char);
}
