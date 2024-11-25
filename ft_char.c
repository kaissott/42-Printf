/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:13:19 by karamire          #+#    #+#             */
/*   Updated: 2024/11/25 07:26:52 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftputstr(va_list ap)
{
	int	i;
	int	size;
	char *str;

	str = va_arg(ap, char*);
	size = ft_strlen(str);
	write(1, str, size);
	return (size);
}

int	ftputchar(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write (1, &c, 1);
	return (1);
}

int	ftpercent(void)
{
	write(1, "%", 1);
	return (1);
}

