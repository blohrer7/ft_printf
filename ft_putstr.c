/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:57:19 by blohrer           #+#    #+#             */
/*   Updated: 2024/11/13 10:45:23 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr(char *str, int *len)
{
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str && *len != -1)
	{
		ft_putchar(*str++, len);
	}
}
