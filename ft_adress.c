/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:41:57 by karamire          #+#    #+#             */
/*   Updated: 2024/11/25 10:55:26 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress_base(void *ptr)
{
	unsigned long adress;
	unsigned long size;
	char	p;
	char *str;

	adress = (unsigned long)ptr;
	str = "0123456789abcdef";
	size = 0;
	if (adress / 16 > 0)
	{
		ft_adress_base((void *)(adress / 16));
		size++;
	}
	p = str[adress % 16];
	write(1, &p, 1);
	return (size);
}
