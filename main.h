#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _strlen(const char *str);
void do_conversion(const char *, char *, va_list ap);
void buffer_copy(char *buffer, char *str, int j, int k);
void switch_format(char *buffer, const char *format,  int i, int j, va_list ap);
#endif
