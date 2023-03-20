/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:23:32 by mbouderr          #+#    #+#             */
/*   Updated: 2022/11/11 20:06:04 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstring(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned long));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(ap, long long), c);
	else if (c == 'p')
		count += ft_adress(va_arg(ap, void *));
	if (c == '%')
		count += write(1, &c, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_convert(str[i], ptr);
		}
		else
			counter += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (counter);
}
