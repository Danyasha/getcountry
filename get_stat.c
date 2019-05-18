#include "get_stat.h"

int countarr(char **ar)
{
    int i = 0;
    while (*ar)
    {
        i++;
        ar++;
    }
    return i;
}

void free_ar(char ***arr)
{
    int i;
    i = 0;
    char **temp = *arr;
    while (temp[i])
    {
        free(temp[i]);
        i++;
    }
    free(*arr);
}

int main(int argn, char **argv)
{
    if (argn != 2)
    {
        printf("Usage: ./get_stat filename\n");
        return 0;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == 0)
    {
        printf("Cannot open file\n");
        return 0;
    }
    if (read(fd, NULL, 0) < 0)
    {
        printf("Cannot read from file\n");
        return 0;
    }

    char *temp;
    char **data;
    t_country *countries;
    t_country *country_temp;
    t_user_id *user_temp;
    while (get_next_line(fd, &temp))
    {
        data = ft_strsplit(temp, ';');
        free(temp);
        if (countarr(data) < 3)
        {
            free_ar(&data);
            continue; 
        }
        country_temp = find_country(countries, data[2]);
        if (!country_temp)
        {
            if(!(country_temp = new_country(data[2])))
            {
                printf("Ошибка выделения памяти\n");
                return 0;
            }
            countries = add_country(countries, country_temp);
        }
        user_temp = make_user(atoi(data[1]),atoi(data[0]));
        country_temp->user_ids = add_user(country_temp->user_ids, user_temp);
        free_ar(&data);
    }

    int count = 0;
    int sum;
    while (countries)
    {
        sum = get_sum_and_count(countries->user_ids, &count);
        printf("%s: sum = %i count_uniq = %i\n", countries->country_name, sum, count);
        countries = countries->next;
    }
    return 0;
}  