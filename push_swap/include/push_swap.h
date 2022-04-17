/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:53:22 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/17 13:52:04 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include "../libft/libft.h"
# include <stdio.h>
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stk;

// typedef struct s_list
// {
// 	int				min;
// 	int				max;
// 	int				size;
// 	struct s_list	*next;
// 	struct s_stack	*end;
// 	t_stk			*(*add)(int ac, char **av, struct s_list list);
// }			t_list;

void	ft_swap(t_stk *node);
void	ft_rotate(t_stk **head);
void	ft_rotate2(t_stk **head);
void	ft_push(t_stk **stack_a, t_stk **stack_b);

void	op_sa(t_stk **stack_a);
void	op_sb(t_stk **stack_b);
void	op_ss(t_stk **stack_a, t_stk **stack_b);
void	op_pb(t_stk **stack_a, t_stk **stack_b);
void	op_pa(t_stk **stack_a, t_stk **stack_b);
void	op_ra(t_stk **stack_a);
void	op_rb(t_stk **stack_b);
void	op_rr(t_stk **stack_a, t_stk **stack_b);
void	op_rra(t_stk **stack_a);
void	op_rrb(t_stk **stack_b);
void	op_rrr(t_stk **stack_a, t_stk **stack_b);
void	add_front(t_stk **top, t_stk *n);

void	printlist(t_stk *n, char *list);
void	short_sort(t_stk **stack_a);
void	insertion_sort(int arr[], int n);
void	organize_any_element(t_stk **stack_a, t_stk **stack_b, int *arr, int j);
void    organize_any_element2(t_stk **stack_a, t_stk **stack_b, int *arr, int j);
int		is_valid_arg(char *str);
int		get_size_stack(t_stk *s);
int		has_duplicates(t_stk *s);
int		*insert_array(t_stk *stack_a, int argms);
int		check_sorted_list(t_stk *stack);
int		ft_atoi(const char *str);

t_stk	*create_new_node(int value);
t_stk	*add_elements_to_list(int ac, char **av);

#endif