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
	char *(*func)(va_list, char *);
} types;

int _printf(const char *format, ...);
int check_valid_format(const char *format);
int length(char *str);
char *copy(char *str, char *copyTo);
char *change_sp(char *s_input, int before, int after, char *var, int var_l);
char *before_after(char *str, int start, types t[],
				   int *before, int *after, int *nul_c, va_list args);
int sp_true(char *str, types t[]);
char *print_string(va_list args, char *flags);
char *print_percent(va_list args, char *flags);
char *print_character(va_list args, char *flags);
char *print_integer(va_list args, char *flags);
char *print_binary(va_list args, char *flags);
char *print_rec(int num, char *p);
char *print_recU(unsigned int num, char *p);
char *print_Uinteger(va_list args, char *flags);
char *print_hexa_upper(va_list args, char *flags);
char *print_hexa_lower(va_list args, char *flags);
char *print_octa(va_list args, char *flags);
char *intToOct(unsigned int num);
char *intToHexa(unsigned int num, char format);
char *get_value(char *str, types t[], va_list args,
				int *nul_c, char *sp_letter, char *flags);
char *intToBin(unsigned int num);
char *print_stringS(va_list args, char *flags);
char *print_pointer(va_list args, char *flags);
void ulong_to_hexa(unsigned long value_p, char *buffer_p);
char *getFlag(char *str, int steps, va_list args);
char *choose_flag(char *str, char *flags, char sp_letter);
char *flag_plus(char *str);
char *flag_hash(char *str, char type);
char *flag_space(char *str);
void int_noFlags(int num, char *p);
void int_flags_handle(va_list args, char *p, char *flags);
char *print_recL(long int num, char *p);
char *print_recS(short int num, char *p);
char *print_Uinteger(va_list args, char *flags);
void Uint_noFlags(unsigned int num, char *p);
void Uint_flags_handle(va_list args, char *p, char *flags);
char *print_recUL(unsigned long int num, char *p);
char *print_recUS(unsigned short int num, char *p);
char *intToOctL(unsigned long int num);
char *intToOctS(unsigned short int num);
char *octa_flags_handle(va_list args, char *p, char *flags);
char *hex_flags_handle(va_list args, char *p, char *flags, char type);
char *intToHexaL(unsigned long int num, char format);
char *intToHexaS(unsigned short int num, char format);
char *binary_flags_handle(va_list args, char *p, char *flags);
char *intToBinL(unsigned long int num);
char *intToBinS(unsigned short int num);
char *print_str_rev(va_list args, char *flags);
char *print_Rot13(va_list args, char *flags);
char *flag_minus(char *str);
char *flag_zero(char *str);
types *sp_struct();
char *flag_width(char *str, char *nums, char fuller);
int get_nums_flag(char *str);

#endif
