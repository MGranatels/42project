/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:21:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/15 20:20:57 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argms;
	int		*arr;
	int		j;

	j = 0;
	argms = ac - 1;
	stack_b = NULL;
	stack_a = add_elements_to_list(ac, av);
	if (!stack_a)
		return (0);
	if (stack_a->next == NULL)
		return (0);
	arr = insert_array(stack_a, argms);
	while (j < 4)
	{
		organize_any_element(&stack_a, &stack_b, arr, j);
		j++;
	}
	j = 500;
	while (stack_a)
		op_pb(&stack_b, &stack_a);
	while (stack_b)
	{
		organize_any_element2(&stack_a, &stack_b, arr, j);
		j--;
	}
}
