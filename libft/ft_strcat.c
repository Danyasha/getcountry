/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:26:37 by btorp             #+#    #+#             */
/*   Updated: 2018/12/11 01:03:36 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0')
	{
		s1[i] = s2[k];
		k++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
