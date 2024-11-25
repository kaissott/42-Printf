/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:34:57 by karamire          #+#    #+#             */
/*   Updated: 2024/11/25 10:51:36 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "LIBFT/libft.h"
#include <stdarg.h>

int	ftputstr(va_list ap);
int	ftputchar(va_list ap);
int	ftpercent(void);
int	basetenconv(va_list ap);
int	printnumber(char *num);
static int	ft_numsize(unsigned int n);
int	putnbr_unsigned(unsigned int n);
int	putnbr_base(unsigned int n, char x);
char	*base(char c);
int	ft_adress_base(void *ptr);

#endif
