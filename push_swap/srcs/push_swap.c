/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:21:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/11 19:31:03 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	organize_any_element(t_stack **stack_a, t_stack **stack_b)
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
}*/

void	organize_any_element(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	if (*stack_b == NULL)
	{
		while (*stack_a)
		{
			printf("List Number : %d\n", (*stack_a)->num);
			if ((*stack_a)->num == arr[j])
			{
				if (i > 5)
				{
					while (i < 10)
					{
						op_rra(stack_a);
						printlist((*stack_a), "LIST A");
						i++;
					}
					op_pb(stack_a, stack_b);
					break;
				}
				else
				{
					while(i > 0)
					{
						op_ra(stack_a);
						i--;
					}
					op_pb(stack_a, stack_b);
					break;
				}
			}
			(*stack_a) = (*stack_a)->next;
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argms;
	int		*arr;
	int		i;
	
	i = 0;
	argms = ac - 1;
	stack_b = NULL;
	stack_a = add_elements_to_list(ac, av);
	arr = insert_array(stack_a, argms);
	i = check_sorted_list(stack_a);
	//short_sort(&stack_a);
	/*while(!i)
	{
		organize_any_element(&stack_a, &stack_b);
		i = check_sorted_list(stack_a);
	}*/
	printlist(stack_a, "A");
	printlist(stack_b, "B");
}
