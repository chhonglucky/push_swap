/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:38:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/07/08 21:01:34 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "csfunc.h"

# define TOP 1
# define BOTTOM 0

/* 양방향 링크드리스트 만들기 */

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				cnt;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

void	stack_init(t_stack **stack_a, t_stack **stack_b);

/* parsing 부분 만들기
	과제의 요구사항에 맞춰 입력 예외사항 만들기 */

int		is_sorted(t_stack **stack);
t_node	*make_node(char *str);
void	parsing(char **argv, t_stack **a);
void	push_bottom(t_stack **stack, t_node *new);
void	dup_check(t_stack **stack, int num);
void	free_split(char ***nums);
int		ft_atoll(char *str);

/* 커맨드 액션 */

void	push(t_stack **stack, t_node *new);
t_node	*pop(t_stack **stack);
void	p(t_stack **to, t_stack **from);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	r(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
void	rev_r(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);

/* 커맨드 링크드리스트 만들기 */

/* 커맨드 리스트 저장 및 출력 */

/* small case 정렬 로직 구현하기 */

void	small_sort(t_stack **a, t_stack **b);
void	sort2(t_stack **a, t_stack **b);
void	sort3(t_stack **a, t_stack **b);
void	sort3_1(t_stack **a, t_stack **b);
void	sort4(t_stack **a, t_stack **b);
void	sort4_1(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
void	sort5_1(t_stack **a, t_stack **b);

/* 정렬 재귀 로직 구현하기 */

void	indexing(t_stack **a);
void	index_sort(int *index_arr, int arr_size);
void	big_sort(t_stack **a, t_stack **b);
void	a_to_b(t_stack **a, t_stack **b, int chunk_num);
void	b_to_a(t_stack **a, t_stack **b);
void	count_rotate(t_stack **b, int *rb_cnt, int *rrb_cnt);
void	big_sort_100(t_stack **a, t_stack **b, int chunk_num);
int		find_pivot(t_stack **stack, int chunk_num);
int		find_min(t_stack **stack);
int		find_max(t_stack **stack);

/* 검토 */

void	free_stack(t_stack **a, t_stack **b);

#endif