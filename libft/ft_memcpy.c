/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:16:32 by btorp             #+#    #+#             */
/*   Updated: 2018/12/17 04:10:20 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;

	if (n == 0 || (dst == src))
		return (dst);
	a = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		a[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (a);
}
