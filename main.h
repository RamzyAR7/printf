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
void print(char *str);
char *change_sp(char *s_input, int before, int after, char *var, int var_l);
char *before_after(char *str, int start, types t[],
int *before, int *after, va_list args);
int sp_true(char *str, types t[]);
char *print_string(va_list args);
char *print_percent(va_list args);
char *print_character(va_list args);
char *get_value(char *str, types t[], va_list args);
#endif