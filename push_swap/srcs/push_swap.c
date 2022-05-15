/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:22:05 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/15 14:33:48 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		size;

	if (ac == 1)
		return (0);
	stk_a = add_elements_to_list(ac, av);
	if (stk_a == NULL)
		return (0);
	stk_b = NULL;
	size = get_size_stack(stk_a);
	if (size == 2)
	{
		if (stk_a->num > stk_a->next->num)
			op_sa(&stk_a);
		clean_stack(&stk_a);
		clean_stack(&stk_b);
		return (0);
	}
	stk_a = check_sort_algr(size, stk_a, stk_b);
	clean_stack(&stk_a);
	clean_stack(&stk_b);
}
