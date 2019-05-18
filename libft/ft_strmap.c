/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:42:51 by btorp             #+#    #+#             */
/*   Updated: 2018/12/11 00:19:04 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen((char*)s));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
		res[i++] = f(*s++);
	return (res);
}
