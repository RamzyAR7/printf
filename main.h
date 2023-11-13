#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct types - struct for types
 * @type: type
 * @func: function
 */
typedef struct types
{
	char type;
	char *(*func)(va_list);
} types;

int _printf(const char *format, ...);
int length(char *str);
char *copy(char *str, char *copyTo);
char *change_sp(char *s_input, int before, int after, char *var, int var_l);
char *before_after(char *str, int start, types t[],
				   int *before, int *after, int *nul_c, va_list args);
int sp_true(char *str, types t[]);
char *print_string(va_list args);
char *print_percent(va_list args);
char *print_character(va_list args);
char *print_integer(va_list args);
char *print_binary(va_list args);
char *print_rec(int num, char *p);
char *print_recU(unsigned int num, char *p);
char *print_Uinteger(va_list args);
char *print_hexa_upper(va_list args);
char *print_hexa_lower(va_list args);
char *print_octa(va_list args);
char *intToOct(unsigned int num);
char *intToHexa(unsigned int num, char format);
char *get_value(char *str, types t[], va_list args, int *nul_c);
char *intToBin(unsigned int num);
char *print_stringS(va_list args);
char *print_pointer(va_list args);
void ulong_to_hexa(unsigned long value_p, char *buffer_p);
char *getFlag(char *str, int steps);
char *choose_flag(char *str, char *flags);
char *flag_plus(char *str);
char *flag_hash(char *str);
char *flag_space(char *str);
#endif
