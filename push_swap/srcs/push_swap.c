/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:21:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/31 18:56:53 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	organize_any_element(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
	{
		while (*stack_a)
		{
			op_pb(stack_b, stack_a);
			if ((*stack_b)->next == NULL)
				op_pb(stack_b, stack_a);
			else if ((*stack_b)->num < (*stack_b)->next->num)
				op_sb(stack_b);
		}
	}
	else if (*stack_a == NULL)
	{	
		while (*stack_b)
		{
			op_pa(stack_b, stack_a);
			if ((*stack_a)->next == NULL)
			{
				op_pa(stack_b, stack_a);
			}
			else if ((*stack_a)->num > (*stack_a)->next->num)
				op_sa(stack_a);
		}
	}
}

void	
	test_sorting(t_stack **stack_a, t_stack **stack_b, int arr[], int n, int argm)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if ((tmp)->num == arr[n])
		{
			if (i > n / 2)
			{
				while (i > 0)
				{
					op_ra(stack_a);
					i--;
				}
			}
			op_pb(stack_b, stack_a);
			i = 0;
		}
		(tmp) = (tmp)->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argms;
	int		*arr;
	int		i;
	int		n;

	i = 0;
	n = 0;
	argms = ac - 1;
	stack_b = NULL;
	stack_a = add_elements_to_list(ac, av);
	arr = insert_array(stack_a, argms);
	printlist(stack_a, "A");
	while (n < argms)
	{
		test_sorting(&stack_a, &stack_b, arr, n, argms);
		n++;
	}
	while (!i)
	{
		organize_any_element(&stack_a, &stack_b);
		i = check_sorted_list(stack_a);
	}
	printlist(stack_a, "A");
	printlist(stack_b, "B");
}
