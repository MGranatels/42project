/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:30:48 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/30 16:50:12 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	**finish_sorting(t_stk **stk_a, t_stk **stk_b)
{
	short_sort_3(stk_a);
	if ((*stk_b)->num < (*stk_b)->next->num)
		op_sb(stk_b);
	op_pa(stk_b, stk_a);
	op_pa(stk_b, stk_a);
	op_ra(stk_a);
	op_ra(stk_a);
	return (stk_a);
}

t_stk	*short_sort_5(t_stk **stk_a, t_stk **stk_b, int *arr)
{
	while (get_size_stack(*stk_a) > 3)
	{
		if ((*stk_a)->num > arr[2])
			op_pb(stk_b, stk_a);
		else
			op_ra(stk_a);
	}
	stk_a = finish_sorting(stk_a, stk_b);
	return (*stk_a);
}

t_stk	*short_sort_3(t_stk **stk_a)
{
	t_stk	*tmp;

	tmp = (*stk_a)->next;
	if (((*stk_a)->num > tmp->num) && (tmp->num < tmp->next->num)
		&& ((*stk_a)->num < tmp->next->num))
		op_sa(stk_a);
	else if ((*stk_a)->num < tmp->num && tmp->num > tmp->next->num
		&& (*stk_a)->num < tmp->next->num)
	{
		op_sa(stk_a);
		op_ra(stk_a);
	}
	else if ((*stk_a)->num > tmp->num && tmp->num > tmp->next->num
		&& (*stk_a)->num > tmp->next->num)
	{
		op_sa(stk_a);
		op_rra(stk_a);
	}
	else if ((*stk_a)->num > tmp->num && tmp->num < tmp->next->num
		&& (*stk_a)->num > tmp->next->num)
		op_ra(stk_a);
	else if ((*stk_a)->num < tmp->num && tmp->num > tmp->next->num
		&& (*stk_a)->num > tmp->next->num)
		op_rra(stk_a);
	return (*stk_a);
}
