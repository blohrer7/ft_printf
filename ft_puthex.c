/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:31:10 by blohrer           #+#    #+#             */
/*   Updated: 2024/11/08 10:52:39 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar(char c, int *len) 
{
    *len += write(1, &c, 1);
}

static void ft_putstr(char *str, int *len) 
{
    if (str == NULL) {
        str = "(null)";
    }
    while (*str) {
        ft_putchar(*str++, len);
    }
}

void ft_putnbr_fd(int n, int fd) 
{
    char c;

    if (n == -2147483648) {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        write(fd, "-", 1);
        n = -n;
    }
    if (n >= 10) {
        ft_putnbr_fd(n / 10, fd);
    }
    c = (n % 10) + '0';
    write(fd, &c, 1);
}

static void ft_puthex(unsigned int n, int uppercase, int *len)
{
    if (n >= 16)
    {
        ft_puthex(n / 16, uppercase, len);
    }
    if (uppercase)
        ft_putchar("0123456789ABCDEF"[n % 16], len);
    else
        ft_putchar("0123456789abcdef"[n % 16], len);
}

// int main(void) 
// {
//     int len = 0;

//     // Test for ft_puthex with lowercase
//     ft_putstr("Hexadecimal (lowercase): ", &len);
//     ft_puthex(255, 0, &len); // 255 in lowercase
//     ft_putchar('\n', &len);

//     // Test for ft_puthex with uppercase
//     ft_putstr("Hexadecimal (uppercase): ", &len);
//     ft_puthex(255, 1, &len); // 255 in uppercase
//     ft_putchar('\n', &len);

//     // Test for ft_puthex with a larger number
//     ft_putstr("Hexadecimal of 4096: ", &len);
//     ft_puthex(4096, 0, &len); // 4096 in lowercase
//     ft_putchar('\n', &len);

//     // Output the total number of characters
//     ft_putstr("Total characters printed: ", &len);
//     ft_putnbr_fd(len, 1); // Output the length to stdout
//     ft_putchar('\n', &len);

//     return 0;
// }