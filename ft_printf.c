/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:36:34 by blohrer           #+#    #+#             */
/*   Updated: 2024/11/18 11:42:52 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_format(char format, va_list args, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), len);
	else if (format == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, len);
	else if (format == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, len);
	else if (format == 'p')
		ft_put_pointer(va_arg(args, void *), len);
	else if (format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format && len != -1)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ft_handle_format(*format, args, &len);
		}
		else
		{
			ft_putchar(*format, &len);
		}
		format++;
	}
	va_end(args);
	if (len == -1)
		return (-1);
	return (len);
}
// # include <stdarg.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
// # include <unistd.h>

// void	ft_putchar(char c, int *len)
// {
// 	int	result;

// 	result = write(1, &c, 1);
// 	if (result == -1)
// 	{
// 		*len = -1;
// 	}
// 	else
// 	{
// 		*len += result;
// 	}
// }
// void	ft_putstr(char *str, int *len)
// {
// 	if (str == NULL)
// 	{
// 		str = "(null)";
// 	}
// 	while (*str && *len != -1)
// 	{
// 		ft_putchar(*str++, len);
// 	}
// }
// void	ft_putnbr(int n, int *counter)
// {
// 	if (*counter == -1)
// 		return ;
// 	if (n == -2147483648)
// 	{
// 		ft_putstr("-2147483648", counter);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar('-', counter);
// 		if (*counter == -1)
// 			return ;
// 		n = -n;
// 	}
// 	if (n >= 10)
// 	{
// 		ft_putnbr(n / 10, counter);
// 		if (*counter == -1)
// 			return ;
// 	}
// 	ft_putchar((n % 10) + '0', counter);
// }
// void	ft_puthex(unsigned long n, int uppercase, int *len)
// {
// 	if (*len == -1)
// 		return ;
// 	if (n >= 16)
// 	{
// 		ft_puthex(n / 16, uppercase, len);
// 		if (*len == -1)
// 			return ;
// 	}
// 	if (uppercase)
// 		ft_putchar("0123456789ABCDEF"[n % 16], len);
// 	else
// 		ft_putchar("0123456789abcdef"[n % 16], len);
// }
// void	ft_put_unsigned(unsigned int n, int *counter)
// {
// 	if (*counter == -1)
// 		return ;
// 	if (n >= 10)
// 	{
// 		ft_put_unsigned(n / 10, counter);
// 		if (*counter == -1)
// 			return ;
// 	}
// 	ft_putchar((n % 10) + '0', counter);
// }
// void	ft_put_pointer(void *ptr, int *counter)
// {
// 	unsigned long	address;

// 	address = (unsigned long) ptr;
// 	ft_putstr("0x", counter);
// 	if (*counter == -1)
// 		return ;
// 	if (address == 0)
// 	{
// 		ft_putchar('0', counter);
// 		return ;
// 	}
// 	ft_puthex(address, 0, counter);
// }
// static void	ft_handle_format(char format, va_list args, int *len)
// {
// 	if (format == 'c')
// 		ft_putchar(va_arg(args, int), len);
// 	else if (format == 's')
// 		ft_putstr(va_arg(args, char *), len);
// 	else if (format == 'd' || format == 'i')
// 		ft_putnbr(va_arg(args, int), len);
// 	else if (format == 'u')
// 		ft_put_unsigned(va_arg(args, unsigned int), len);
// 	else if (format == 'x')
// 		ft_puthex(va_arg(args, unsigned int), 0, len);
// 	else if (format == 'X')
// 		ft_puthex(va_arg(args, unsigned int), 1, len);
// 	else if (format == 'p')
// 		ft_put_pointer(va_arg(args, void *), len);
// 	else if (format == '%')
// 		ft_putchar('%', len);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int		len;
// 	va_list	args;

// 	len = 0;
// 	va_start(args, format);
// 	while (*format && len != -1)
// 	{
// 		if (*format == '%' && *(format + 1))
// 		{
// 			format++;
// 			ft_handle_format(*format, args, &len);
// 		}
// 		else
// 		{
// 			ft_putchar(*format, &len);
// 		}
// 		format++;
// 	}
// 	va_end(args);
// 	if (len == -1)
// 		return (-1);
// 	return (len);
// }

// int main(void)
// {
//     int ret_ft_printf;
//     int ret_printf;

//     ret_ft_printf = ft_printf("ft_printf - Char: %c\n", 'A');
//     ret_printf = printf("printf    - Char: %c\n", 'A');
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     ret_ft_printf = ft_printf("ft_printf - String: %s\n", "Hello, world!");
//     ret_printf = printf("printf    - String: %s\n", "Hello, world!");
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     ret_ft_printf = ft_printf("ft_printf - NULL-String: %s\n", NULL);
//     ret_printf = printf("printf    - NULL-String: %s\n", NULL);
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     ret_ft_printf = ft_printf("ft_printf - Decimal: %d, Integer: %i\n",
// 12345, -6789);
//     ret_printf = printf("printf    - Decimal: %d, Integer: %i\n", 12345,
// -6789);
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     ret_ft_printf = ft_printf("ft_printf - Unsigned: %u\n", 4294967295U);
//     ret_printf = printf("printf    - Unsigned: %u\n", 4294967295U);
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     ret_ft_printf = ft_printf("ft_printf - Hex Lowercase: %x, Uppercase:
// %X\n", 24433U, -10);
//     ret_printf = printf("printf    - Hex Lowercase: %x, Uppercase: %X\n",
// 24433U, -10);
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     int x = 42;
//     ret_ft_printf = ft_printf("ft_printf - Pointer: %p\n", &x);
//     ret_printf = printf("printf    - Pointer: %p\n", &x);
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     ret_ft_printf = ft_printf("ft_printf - Percent: %%\n");
//     ret_printf = printf("printf    - Percent: %%\n");
//     printf("Return Werte: ft_printf = %d, printf = %d\n\n", ret_ft_printf,
// ret_printf);

//     return (0);
// }
