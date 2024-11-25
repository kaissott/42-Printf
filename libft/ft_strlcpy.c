/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:35:03 by karamire          #+#    #+#             */
/*   Updated: 2024/11/20 16:59:24 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	s = 0;
	while (src[s] != '\0')
		s++;
	if (size == 0)
		return (s);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
int	main(void)
{
	char	str[] = "aaaaaaaaaaaaaaaa";
	char	dest[] = "";

	printf("Base : %zu", ft_strlcpy(dest, str, 11));
}