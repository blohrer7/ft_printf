/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:18:28 by blohrer           #+#    #+#             */
/*   Updated: 2024/11/13 11:01:29 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (*counter == -1)
		return ;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", counter);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', counter);
		if (*counter == -1)
			return ;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, counter);
		if (*counter == -1)
			return ;
	}
	ft_putchar((n % 10) + '0', counter);
}
