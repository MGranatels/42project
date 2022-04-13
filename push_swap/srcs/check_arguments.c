/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:12:17 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/04/12 09:17:27 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int ft_strcmp(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if ((*str1) - (*str2))
            return ((*str1) - (*str2));
        str1++;
        str2++;
    }
    return ((*str1) - (*str2));
}

int is_valid_arg(char *str)
{
    char *tmp;
    unsigned int len;

    tmp = str;
    if(*tmp == '-' || *tmp == '+')
		tmp++;
	while (*tmp == '0')
		tmp++;
	len = ft_strlen(str) - (tmp - str);
	if (len > 10 || (ft_strlen(str) == 1 && (*str == '+' || *str == '-')))
		return (0);
	while (*tmp)
        if (!ft_isdigit(*tmp++))
            return (0);
    if (*str == '-') {
        if (len == 10 && ft_strcmp(str + ft_strlen(str) - len, "2147483648") > 0)
            return (0);
    }
    else if (len == 10 && ft_strcmp(str + ft_strlen(str) - len, "2147483647") > 0)
            return (0);
    return (1);
}

int	get_size_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int has_duplicates(t_stack *s)
{
	t_stack *current;
	t_stack *next;
	int cur_value;
	unsigned int i;
	unsigned int size;

	if (!s)
		return (0);
	next = s;
	size = get_size_stack(s);
	while (--size > 0)
	{
		cur_value = next->num;
		current = next->next;
		next = next->next;
		i = size;
		while (i-- > 0) 
		{
			if (current->num == cur_value)
				return (1);
			current = current->next;
		}
	}
	return (0);
}
