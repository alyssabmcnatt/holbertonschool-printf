#include "main.h"

/**
 * to_print - checks if a char is printable
 * @c: char to be evaluated
 * Return: 1 if c is printable, 0 otherwise
 */
int to_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa_append - append ascci in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASSCI CODE
 * Return: always 3
 */
int hexa_append(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * digit_verify - this verifies if a char is a digit
 * @c: char to be evaluated
 *
 * return: 1 if c is a digit, 0 otherwise
 */
int digit_verify(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * num_convert - this casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int num_convert(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * unsig_convert - this casrs a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int unsig_convert(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

