/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:29:46 by karamire          #+#    #+#             */
/*   Updated: 2024/11/25 12:38:04 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_checkconv (const char c, va_list ap)
{
	int	printlen;
	int	len;

	len = 0;
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
		printlen = ft_adress_base(va_arg(ap, void *), &len) + 2;
	}
	else if (c == '\0')
		return 0;
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
	printlen = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			printlen += ft_checkconv(str[i + 1], ap);
			i++;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			printlen++;
		}
		i++;
	}
	return (printlen);
}
int	main(void)
{
	int	a = 123489;

	int	*d = &a;

	printf("%d\n",ft_printf("%p\n", d));
	printf("%d\n",printf("%p\n", d));

	/* ft_printf("%\n", 123465);
 */
}
