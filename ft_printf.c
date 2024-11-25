/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:29:46 by karamire          #+#    #+#             */
/*   Updated: 2024/11/25 11:05:08 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_checkconv (const char c, va_list ap)
{
	int	printlen;

	if (c == 's')
		printlen = ftputstr(ap);
	else if (c == 'c')
		printlen = ftputchar(ap);
	else if (c == '%')
		printlen = ftpercent();
	else if (c == 'i' || c == 'd')
		printlen = basetenconv(ap);
	else if (c == 'u')
		printlen = putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		printlen = putnbr_base(va_arg(ap, unsigned int), c);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		printlen = ft_adress_base(va_arg(ap, void *));
	}
	return (printlen);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	const char *str;
	int	printlen;
	int	i;

	str = format;
	va_start(ap, format);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			printlen += ft_checkconv(str[i + 1], ap);
			i++;
		}
		else
			write(1, &str[i], 1);
		printlen++;
		i++;
	}
	return (printlen);
}
int	main(void)
{
	int	a = 12;

	int	*d = &a;

	ft_printf("%p", d);
	printf("%p", d);

}
