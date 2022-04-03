/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:16:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/31 18:27:20 by mgranate         ###   ########.fr       */
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

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->next = NULL;
	return (first);
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

t_stack	*add_elements_to_list(int ac, char **av)

{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = create_new_node();
	tmp = first;
	while (i < ac)
	{
		tmp->num = ft_atoi(av[i]);
		if (i < ac - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	return (first);
}
