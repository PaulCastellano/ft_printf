#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int main()
{
    int orig;
    int my;
    wchar_t *str = L"asфв";

    setlocale(LC_ALL, "");
    my = ft_printf("|%%| |%d| |%i| |%s| |%C| |%S| |%p|\n", 10, 100, "asd", 3000, str, &orig);
    orig = printf("|%%| |%d| |%i| |%s| |%C| |%S| |%p|\n", 10, 100, "asd", 3000, str, &orig);
    printf("|%d| - |%d|", my, orig);
    return (0);
}