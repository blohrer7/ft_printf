/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:31:10 by blohrer           #+#    #+#             */
/*   Updated: 2024/11/13 12:41:45 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, int uppercase, int *len)
{
	if (*len == -1)
		return ;
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

//     return (0);
// }
