#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/**
 * struct fmt - Struct op
 * @fmt: the format
 * @fn: the function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int ,int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: the format
 * @fmt_t: the function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

/* functions to print chars and strings */
int print_char(va_list data, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list data, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list data, char buffer[],
		int flags, int width, int precision, int size);

/* functions to print numbers */
int print_int(va_list data, char buffer[],
		int flags, int width, int precision, int size);

/* utils */
int to_print(char);
int hexa_append(char, char[], int);
int digit_verify(char);

long int num_convert(long int num, int size);
long int unsig_convert(unsigned long int num, int size);

#endif
