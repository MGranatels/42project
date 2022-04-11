/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:16:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/11 20:01:27 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printlist(t_stack *n, char *list)
{
	printf("\n=======%s=======\n", list);
	while (n)
	{
		printf("%d ", n->num);
		n = n->next;
	}
	printf("\n===============\n");
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
void	short_sort(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_a)->next;
	if (((*stack_a)->num > tmp->num) && (tmp->num < tmp->next->num)
		&& ((*stack_a)->num < tmp->next->num))
		op_sa(stack_a);
	else if ((*stack_a)->num < tmp->num && tmp->num > tmp->next->num
		&& (*stack_a)->num < tmp->next->num)
	{
		op_sa(stack_a);
		op_ra(stack_a);
	}
	else if ((*stack_a)->num > tmp->num && tmp->num > tmp->next->num
		&& (*stack_a)->num > tmp->next->num)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if ((*stack_a)->num > tmp->num && tmp->num < tmp->next->num
		&& (*stack_a)->num > tmp->next->num)
		op_ra(stack_a);
	else if ((*stack_a)->num < tmp->num && tmp->num > tmp->next->num
		&& (*stack_a)->num > tmp->next->num)
		op_rra(stack_a);
}

int is_valid_arg(char *str)
{
    char *tmp;
    unsigned int len;

    tmp = str;
    if (*tmp == '-')
        tmp++;
    while (*tmp)
        if (!ft_isdigit(*tmp++))
            return (0);
    len = ft_strlen(str);
    if (*str == '-') {
        if (len >= 11 && ft_strncmp(str, "-2147483648", 10) > 0)
            return (0);
    }
    else if (len >= 10 && ft_strncmp(str, "2147483647", 10) > 0)
            return (0);
    return (1);
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


t_stack	*add_elements_to_list(int ac, char **av)
{
	int		j;
	t_stack	*stack;
	char	**split;
	t_stack  *head;

	stack = NULL;
	head = NULL;
	while (--ac > 0)
	{
		split = ft_split(av[ac], ' ');
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
				clean_split(split);
				return (0);
			}
		}
	}
	clean_split(split);
	return (head);
}
