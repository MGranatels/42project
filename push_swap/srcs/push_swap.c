/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:21:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/14 11:07:10 by mgranate_ls      ###   ########.fr       */
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
	while (j < 2)
	{
		organize_any_element(&stack_a, &stack_b, arr, j);
		j++;
	}
} 	
