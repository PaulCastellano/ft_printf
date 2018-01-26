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

/*static int (int *p);
{
  int ret;


  return (ret);
}*/

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

void ft_printf_unic(int c)
{
  if (c < 0x80)
  {
    ft_putchar(c);
  }
  else if (c < 0x800)
  {
    ft_putchar(0xC0 | (c >> 6));
    ft_putchar(0x80 | (c & 0x3F));
  }
  else if (c < 0x10000)
  {
    ft_putchar(0xE0 | (c >> 12));
    ft_putchar(0x80 | ((c >> 6) & 0x3F));
    ft_putchar(0x80 | (c & 0x3F));
  }
  else if (c < 0x200000)
  {
    ft_putchar(0xF0 | (c >> 18));
    ft_putchar(0x80 | ((c >> 12) & 0x3F));
    ft_putchar(0x80 | ((c >> 6) & 0x3F));
    ft_putchar(0x80 | (c & 0x3F));
  }
}

static  int   ft_printf_string(char *str)
{
  ft_putstr(str);
  return(ft_strlen(str));
}

int         ft_printf(const char *format, ...)
{
  int     *p;
  int     c;
  int     i;
  int     in;
  char    *s;
  va_list ls;
  int     ret;

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
      ft_printf_unic(c);
      ret++;
      i++;
    }
  /*  else if (format[i] == '%' && format[i + 1] == 'p')
    {
      p = va_arg(ls, int*);
      ret = ret + ft_printf_p(p);
      i++;
    }*/
    if (format[i - 1] == '%' && format[i - 2] != '%')
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
