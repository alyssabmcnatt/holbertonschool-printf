#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*sizes */
#define S_LONG 2
#define S_SHORT 1

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

/* functions */

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
int print_binary(va_list data, char buffer[],
		int flags, int width, int precision, int size);
int unsig_p(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int octal_p(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int hexadec_p(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* function to print non printable character */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* function to print memory address */
int var_point(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* functions to handle other specifiers */
int flags_p(const char *format, int *i);
int print_width(const char *format, int *i, va_list arg);
int exact_p(const char *format, int *i, va_list list);
int size_p(const char *format, int *i);

/* function to print string in reverse */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* function to print a string in rot 13 */
int rotstr13_p(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */
int char_handle(char c, char buffer[],
		int flags, int width, int precision, int size);
int digit_write(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int buff_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int num_pointer(char buffer[], int ind, int length,
		int width, int flags, int padd, char extra_c, int padd_start);

int num_unsig(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

/* utils */
int to_print(char);
int hexa_append(char, char[], int);
int digit_verify(char);

long int num_convert(long int num, int size);
long int unsig_convert(unsigned long int num, int size);

#endif
