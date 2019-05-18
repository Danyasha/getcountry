#include "get_stat.h"

int			get_sum_and_count(t_user_id *ids, int *count)
{
	int	sum = 0;
	int	i = 0;
	while (ids != NULL)
	{
		i++;
		sum += ids->count;
		ids = ids->next;
	}
	*count = i;
	return sum;
}

t_country 	*find_country(t_country *countries, char *name)
{
	while (countries != NULL)
	{
		if (strcmp(countries->country_name, name) == 0)
			return countries;
		else
			countries = countries->next;	
	}
	return NULL;
}

t_country	*new_country(char *name)
{
	t_country *new_country = (t_country*)malloc(sizeof(t_country));
	if (new_country == NULL)
	{
		printf("Ошибка выделения памяти");
		return NULL;
	}
	int len = strlen(name);
	new_country->country_name = (char*)malloc(sizeof(char) * (len + 1));
	if (new_country->country_name == NULL)
	{
		printf("Ошибка выделения памяти");
		free(new_country);
		return NULL;
	}
	strcpy(new_country->country_name, name);
	new_country->user_ids = NULL;
	new_country->next = NULL;
	return new_country;
}

t_country *add_country(t_country *countries, t_country *new_country)
{
	if (countries == NULL)
		return new_country;
	new_country->next = countries;
	return new_country;
}

t_user_id *add_user(t_user_id *ids, t_user_id *new_id)
{
	if (ids == NULL)
		return new_id;
	new_id->next = ids;
	return new_id;
}

t_user_id *make_user(unsigned int count, unsigned int user_id)
{
	t_user_id *new_id = (t_user_id*)malloc(sizeof(t_user_id));
	if (new_id == NULL)
	{
		printf("Ошибка выделения памяти");
		return NULL;
	}
	new_id->count = count;
	new_id->user_id = user_id;
	new_id->next = NULL;
	return new_id;
}

void	free_users(t_user_id **ids)
{
	t_user_id *next;
	t_user_id *temp = *ids;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
void	free_countries(t_country **country)
{
	t_country *next;
	t_country *t = *country;
	while (t)
	{
		next = t->next;
		free_users(&(t->user_ids));
		free(t->country_name);
		free(t);
		t = next;
	}
}