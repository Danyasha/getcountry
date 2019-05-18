#ifndef GET_STAT_H

# define GET_STAT_H
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

typedef	struct	s_user_id
{
	unsigned	int		user_id;
	unsigned	int		count;
	struct s_user_id	*next;
}				t_user_id;

typedef	struct	s_country
{
	char		*country_name;
	t_user_id	*user_ids;
	struct s_country	*next;
}				t_country;
int			get_sum_and_count(t_user_id *ids, int *count);
t_country	*new_country(char *name);
t_country	*add_country(t_country *countries, t_country *new_country);
t_user_id	*add_user(t_user_id *ids, t_user_id *new_id);
t_user_id	*make_user(unsigned int count, unsigned int user_id);
t_country	*find_country(t_country *countries, char *name);
t_country	*new_country(char *name);
#endif