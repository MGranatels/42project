/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:16:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/11 21:00:28 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printlist(t_stack *n, char *list)
{
	ft_printf("\n=======%s=======\n", list);
	while (n)
	{
		ft_printf("%d ", n->num);
		n = n->next;
	}
	ft_printf("\n===============\n");
}

t_stack	*create_new_node(int value) //creates a new stack element
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->num = value;
	s->next = NULL;
	return (s);
}

int ft_strcmp(char *str1, char *str2)
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

int has_duplicates(t_stack *s){
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

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clean_stack(t_stack	*s)
{
	t_stack *temp;
    if (s) 
	{
        s->next = 0;
        while (s) 
		{
            temp = s->next;
            free(s);
            s = temp;
        }
    }
}

t_stack	*add_elements_to_list2(char **split, t_stack *head, t_stack *stack)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (is_valid_arg(split[j]))
		{
			stack = create_new_node(ft_atoi(split[j++]));
			stack->next = head;
			head = stack;
		}
		else
		{
			ft_printf("Error\n");
			clean_split(split);
			return (0);
		}
	}
	return (head);
}

t_stack	*add_elements_to_list(int ac, char **av)
{
	t_stack	*stack;
	char	**split;
	t_stack  *head;

	stack = NULL;
	head = NULL;
	while (--ac > 0)
	{
		split = ft_split(av[ac], ' ');
		head = add_elements_to_list2(split, head, stack);
		if (head == NULL)
			return (0);
	}
	clean_split(split);
	if (has_duplicates(head))
	{
		ft_printf("Error\n");
		clean_stack(head);
		return (0);
	}
	return (head);
}
