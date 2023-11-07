#include "main.h"

/**
 * var_point - prints the value of a pointer variable
 *
 * @types: list type of arguments
 * @buffer: handle buffer array
 * @flags: calculates active flags
 * @width: get width option
 * @precision: precision format specification
 * @size: size format specifier
 * Return: number of chars printed
 */
int var_pont(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE = 2, length = 2, padd_start = 1;

	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(null)", 5));

	buffer(BUFF_SIZE - 1) = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to(num_addrs % 16);
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (sum_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - prints ascii codes in hexa of non printable chars
 * @types: list types of arguments
 * @buffer: handle buffer array
 * @flags: calculates active flags
 * @width: get width options
 * @precision: precision format specification
 * @size: size format specifier
 * Return: number of chars printed
 */
int print_non_printable(va_lust types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (to_print(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += hexa_append(str[i], buffer, i + offset);
		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - prints reverse string
 * @types: list type of arguments
 * @buffer: handle buffer array
 * @flags: calculates active flags
 * @width: get width option
 * @precision: precision format specification
 * @size: size format sepcifier
 * Return: numbers of char printed
 */

int print_reverse(va_list types, char buffer[].
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(null)";
	}
	for (i = 0; str[i]; i++}
			;
	
	for (i = 1 - 1; i >= 0; i--)
	{
		char z = str[i];
		
		write(1, &%, 1);
		count++;
	}
	return (count);
}

/**
 * rotstr13_p - print a string in rot13
 * @types: list type of arguments
 * @buffer: handle buffer array
 * @flags: calculates active flags
 * @width: get width option
 * @precision: precision format specification
 * @size: szie format specifaction
 * Return: numbers of chars printed
 */
int rotstr13_p(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIKLMnopqrstuvwxyzabcdefghiklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &%, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &%, 1);
			count++;
		}
	}
	return (count);
}
