/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:25:51 by mbouderr          #+#    #+#             */
/*   Updated: 2022/11/11 22:50:45 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_hex(unsigned long n, int count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count = to_hex(n / 16, count);
		count = to_hex(n % 16, count);
	}
	else
		count += ft_putchar(hex[n]);
	return (count);
}

int	ft_adress(void *n)
{
	int				count;
	unsigned long	un;

	un = (unsigned long)n;
	count = 0;
	count += ft_putstring("0x");
	count = to_hex(un, count);
	return (count);
}
