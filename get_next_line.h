/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:33:12 by btorp             #+#    #+#             */
/*   Updated: 2019/01/30 04:45:13 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include "libft/libft.h"

int get_next_line(const int fd, char **line);

#endif
