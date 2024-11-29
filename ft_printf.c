/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:29:46 by karamire          #+#    #+#             */
/*   Updated: 2024/11/29 13:52:31 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_checkconv(const char c, va_list ap)
{
	void	*adress;

	if (c == 's')
		return (ftputstr(ap));
	else if (c == 'c')
		return (ftputchar(ap));
	else if (c == '%')
		return (ftpercent());
	else if (c == 'i' || c == 'd')
		return (basetenconv(ap));
	else if (c == 'u')
		return (putnbr_unsigned(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (putnbr_base(va_arg(ap, unsigned int), c));
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
	int		printlen;
	int		i;
	int		check;

	va_start(ap, format);
	i = 0;
	printlen = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
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

/* int	main(void)
{

	void * a;
	a = 0;

	ft_printf("len : %d\n",ft_printf(NULL, a, a));
	//printf("len : %d\n", printf(NULL, a, a));

 //ft_printf("%\n", 123465);

} */
/* int     main(void)
{
        int             i;
        char    *s;
        void    *ptr;

        i = 8;
        // s = "oui oui baguette";
        s = NULL;
        ptr = s;
        printf("int : %d\n\n", ft_printf("my oui p%%%p oui\n", ptr));
        printf("int : %d\n\n", printf("42 oui p%%%p oui\n", ptr));
        printf("int : %d\n\n", ft_printf("my oui s%%%s oui\n", NULL));
        printf("int : %d\n\n", printf("42 oui s%%%s oui\n", NULL));
        printf("int : %d\n\n", ft_printf("my oui u : %%%u oui\n", i));
        printf("int : %d\n\n", printf("42 oui u : %%%u oui\n", i));
        printf("int : %d\n\n", ft_printf("my oui i%%%i oui\n", i));
        printf("int : %d\n\n", printf("42 oui i%%%i oui\n", i));
        printf("int : %d\n\n", ft_printf("my oui d%%%d oui\n", i));
        printf("int : %d\n\n", printf("42 oui d%%%d oui\n", i));
        printf("int : %d\n\n", ft_printf("my oui x%%%x oui\n", i));
        printf("int : %d\n\n", printf("42 oui x%%%x oui\n", i));
        printf("int : %d\n\n", ft_printf("my oui X%%%X oui\n", i));
        printf("int : %d\n\n", printf("42 oui X%%%X oui\n", i));
        printf("int : %d\n\n", ft_printf("my oui %%%a oui\n", 35));
        printf("int : %d\n\n", printf("42 oui %%%a oui\n", 35));
        ft_printf(" %d\n %d\n %d\n %d\n %d\n %d\n %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
        printf(" %d\n %d\n %d\n %d\n %d\n %d\n %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
        printf("int : %d\n\n", ft_printf(NULL));
        printf("int : %d\n\n", printf(NULL));
} */

