/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:53:22 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/30 20:33:06 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stk;

void	ft_swap(t_stk *node);
void	ft_rotate(t_stk **head);
void	ft_rotate2(t_stk **head);
void	ft_push(t_stk **stk_a, t_stk **stk_b);

void	op_sa(t_stk **stk_a);
void	op_sb(t_stk **stk_b);
void	op_ss(t_stk **stk_a, t_stk **stk_b);
void	op_pb(t_stk **stk_a, t_stk **stk_b);
void	op_pa(t_stk **stk_a, t_stk **stk_b);
void	op_ra(t_stk **stk_a);
void	op_rb(t_stk **stk_b);
void	op_rr(t_stk **stk_a, t_stk **stk_b);
void	op_rra(t_stk **stk_a);
void	op_rrb(t_stk **stk_b);
void	op_rrr(t_stk **stk_a, t_stk **stk_b);

//void	printlist(t_stk *n, char *list);
void	clean_stack(t_stk	**s);
void	organize_any_element2(t_stk **stk_a, t_stk **stk_b, int *arr, int j);
void	organize_any_element(t_stk **stk_a, t_stk **stk_b, int *arr, int j);

int		is_valid_arg(char *str);
int		get_size_stack(t_stk *s);
int		has_duplicates(t_stk *s);
int		*insert_array(t_stk *stk_a, int argms);
int		check_sorted_list(t_stk **stack);
int		ft_atoi(const char *str);

t_stk	*check_sort_algr(int size, t_stk *stk_a, t_stk *stk_b);
t_stk	*big_stack(t_stk *stk_a, t_stk *stk_b, int size, int *arr);
t_stk	*short_stack(t_stk *stk_a, t_stk *stk_b, int size, int *arr);
t_stk	*short_sort_3(t_stk **stk_a);
t_stk	*add_elements_to_list(int ac, char **av);
t_stk	*short_sort_5(t_stk **stk_a, t_stk **stk_b, int *arr);

#endif