/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:21:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/13 11:37:37 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argms;
	int		*arr;
	int		i;
	int		j;
	
	j = 0;
	i = 0;
	argms = ac - 1;
	stack_b = NULL;
	stack_a = add_elements_to_list(ac, av);
	if (!stack_a)
		return (0);
	if (stack_a->next == NULL)
		return (0);
	arr = insert_array(stack_a, argms);
	while (stack_a)
	{
		organize_any_element(&stack_a, &stack_b, arr, j);
		j++;
	}
	if (stack_b->num < stack_b->next->num)
		op_sb(&stack_b);
	while (stack_b)
		op_pa(&stack_b, &stack_a);
	printlist(stack_a, "A");
} 	
