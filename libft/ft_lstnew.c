/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:49:27 by btorp             #+#    #+#             */
/*   Updated: 2019/01/25 19:38:51 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	a->content = malloc(content_size);
	if (a->content == NULL)
	{
		free(a);
		a = NULL;
		return (NULL);
	}
	if (content == NULL)
	{
		a->content = NULL;
		a->content_size = content_size;
		a->next = NULL;
		return (a);
	}
	a->content = ft_memcpy(a->content, content, content_size);
	a->content_size = content_size;
	a->next = NULL;
	return (a);
}
