#include "main.h"

/**
 * _printf - A function that produces output according to a format
 * @format: Character string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *buffer;
	int y;

	if (format == NULL)
	{
		return (-1);
	}
	buffer = (char *) malloc((_strlen(format) * sizeof(format)) * 1000);
	va_start(ap, format);
	if (buffer == NULL)
	{
		return (-1);
	}
	else
	{
		buffer[0] = '\0';
	}
	do_conversion(format, buffer, ap);
	va_end(ap);
	y = write(1, buffer, _strlen(buffer));
	free(buffer);
	return (y);
}

/**
 * _strlen - A function that return the length of a string
 * @str: String parameter
 * Return: Return String length
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * do_conversion - A function that do string literal to value conversion
 * @buffer: String parameter
 * @ap: Va_list argument
 * Return: void
 */
void do_conversion(const char *format, char *buffer, va_list ap)
{
	int i = 0;
	int j = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%' && (format[i + 1] != 'c' ||
					(format[i + 1] != 's' || format[i + 1] != '%')))
		{
			buffer[j] = format[i];
				j++;
				i++;
		}
		else
		{
			/**switch_format(buffer, format, i, j, ap);**/
			char *str;
			int k;

			switch (format[(i + 1)])
			{
				case 'c':
					buffer[j] = (char)(va_arg(ap, int));
					j++;
					i = i + 2;
					break;
				case 's':
					k = 0;
					str = va_arg(ap, char *);
					if (str == ((char *)0))
					{
						str = "(null)";
						buffer_copy(buffer, str, j, k);
						i = i + 2;
					}
					else
					{
						buffer_copy(buffer, str, j, k);
						i = i + 2;
					}
					break;
				case '%':
					buffer[j] = '%';
					j++;
					i = i + 2;
					break;
				default:
					return;
			}
		}
		}
}

/**
 * buffer_copy - A function that copies to the buffer
 * @str: String argument
 * @buffer: Buffer argument
 * @j: Counter j
 * @i: counter i
 * Return: void
 */
void buffer_copy(char *buffer, char *str, int j, int k)
{
	while (str[k] != '\0')
	{
		buffer[j] = str[k];
		k++;
		j++;
	}
}

/**
 * switch_format - A function to switch through the format specifier
 * @buffer:
 * @format:
 * @str
 * @i:
 * @j:
 * @k:
 * @ap:
 */
/**void switch_format(char *buffer, const char *format, int i, int j, va_list ap)
{
	char *str;
	int k;
	switch (format[(i + 1)])
	{
		case 'c':
			buffer[j] = (char)(va_arg(ap, int));
			j++;
			i = i + 2;
			break;
		case 's':
			k = 0;
			str = va_arg(ap, char *);
			if (str == ((char *)0))
			{
				str = "(null)";
				buffer_copy(buffer, str, j, k);
				i = i + 2;
			}
			else
			{
				buffer_copy(buffer, str, j, k);
				i = i + 2;
			}
			break;
		case '%':
			buffer[j] = '%';
			j++;
			i = i + 2;
			break;
		default:
			return;
	}
}**/
