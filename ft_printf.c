/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:29:46 by karamire          #+#    #+#             */
/*   Updated: 2024/11/29 08:36:06 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_checkconv (const char c, va_list ap)
{
	void*	adress;

	if (c == 's')
		return(ftputstr(ap));
	else if (c == 'c')
		return(ftputchar(ap));
	else if (c == '%')
		return(ftpercent());
	else if (c == 'i' || c == 'd')
		return(basetenconv(ap));
	else if (c == 'u')
		return(putnbr_unsigned(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return(putnbr_base(va_arg(ap, unsigned int), c));
	else if (c == 'p')
	{
		adress = va_arg(ap, void *);
		if (adress == NULL)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_adress_base(adress));
	}
	return (-1);
}


int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	printlen;
	int	i;
	int	check;

	va_start(ap, format);
	i = 0;
	printlen = 0;
	while (format[i])
	{
		check = 0;
		if (format[i] == '%')
		{
			check = ft_checkconv(format[i + 1], ap);
			if (check < 0)
				return (-1);
			printlen += check;
			i++;
		}
		else
			printlen += write(1, &format[i], 1);
		i++;
	}
	return (printlen);
}
int	main(void)
{

	void * a;
	a = 0;

	ft_printf("len : %d\n",ft_printf(" %a", a, a));
	printf("len : %d\n", printf(" %a", a, a));

 //ft_printf("%\n", 123465);

}
