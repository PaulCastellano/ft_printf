/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:48:20 by egaraz            #+#    #+#             */
/*   Updated: 2018/01/26 11:27:36 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static  int    ft_printf_int(int num)
{
  int i;

  ft_putnbr(num);
  i = 0;
  if (num < 0)
    i++;
  while(num != 0)
  {
    num = num / 10;
    i++;
  }
  return(i);
}

static int ft_printf_unic(int c)
{
  int ret;

  ret = 0;
  if (c < 0x80)
  {
    ft_putchar(c);
    return (1);
  }
  else if (c < 0x800)
  {
    ft_putchar(0xC0 | (c >> 6));
    ft_putchar(0x80 | (c & 0x3F));
    return (2);
  }
  else if (c < 0x10000)
  {
    ft_putchar(0xE0 | (c >> 12));
    ft_putchar(0x80 | ((c >> 6) & 0x3F));
    ft_putchar(0x80 | (c & 0x3F));
    return (3);
  }
  else if (c < 0x200000)
  {
    ft_putchar(0xF0 | (c >> 18));
    ft_putchar(0x80 | ((c >> 12) & 0x3F));
    ft_putchar(0x80 | ((c >> 6) & 0x3F));
    ft_putchar(0x80 | (c & 0x3F));
    return (4);
  }
  return (0);
}

static int    ft_printf_adr(int c)
{
  int ret;
  int ptr;

  ptr  = (int) &c;
  ft_putchar(*(1 + (unsigned char*)&ptr));
  ft_putchar(*((unsigned char*)&ptr));
  while(ptr != 0)
  {
    ptr = ptr / 10;
    ret++;
  }
  return (ret);
}

static int    ft_printf_unicstr(int *str)
{
  int i;
  int ret;

  ret = 0;
  while (str[i])
  {
    ret = ret + ft_printf_unic(str[i]);
    i++;
  }
  return (ret);
}

static  int   ft_printf_string(char *str)
{
  ft_putstr(str);
  return(ft_strlen(str));
}

int         ft_printf(const char *format, ...)
{
  int           *str;
  int           *p;
  int           c;
  int           i;
  int           in;
  char          *s;
  va_list       ls;
  int           ret;

  va_start(ls, format);
  i = 0;
  ret = 0;
  while (format[i])
  {
    if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
    {
      in = va_arg(ls, int);
      ret = ret + ft_printf_int(in);
      i++;
    }
    else if (format[i] == '%' && format[i + 1] == 's')
    {
      s = va_arg(ls, char*);
      ret = ret + ft_printf_string(s);
      i++;
    }
    else if (format[i] == '%' && format[i + 1] == '%')
    {
      ft_putchar('%');
      ret++;
      i++;
    }
    else if (format[i] == '%' && format[i + 1] == 'c')
    {
      c = va_arg(ls, int);
      ft_putchar(c);
      ret++;
      i++;
    }
    else if (format[i] == '%' && format[i + 1] == 'C')
    {
      c = va_arg(ls, int);
      ret = ret + ft_printf_unic(c);
      i++;
    }
    else if (format[i] == '%' && format[i + 1] == 'S')
    {
      str = va_arg(ls, int*);
      ret = ret + ft_printf_unicstr(str);
      i++;
    }
    else if (format[i] == '%' && format[i + 1] == 'p')
    {
      c = va_arg(ls, int);
      ret = ret + ft_printf_adr(c);
      i++;
    }
    else if (format[i - 1] == '%' && format[i - 2] != '%')
      i++;
    else
    {
      ft_putchar(format[i]);
      ret++;
      i++;
    }
  }
  return (ret);
}
