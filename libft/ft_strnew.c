/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:43:13 by btorp             #+#    #+#             */
/*   Updated: 2019/05/18 15:36:51 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	a = (char*)malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	ft_bzero(a, size + 1);
	return (a);
}
