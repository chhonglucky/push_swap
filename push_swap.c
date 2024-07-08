/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:51:13 by chanhhon          #+#    #+#             */
/*   Updated: 2024/07/08 21:08:01 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		unix_error("not enough arguments");
	stack_init(&stack_a, &stack_b);
	parsing(argv, &stack_a);
	indexing(&stack_a);
	if (stack_a->cnt <= 5)
		small_sort(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
}

void	stack_init(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (t_stack *)shell_malloc(sizeof(t_stack));
	*stack_b = (t_stack *)shell_malloc(sizeof(t_stack));
	(*stack_a)->cnt = 0;
	(*stack_a)->top = NULL;
	(*stack_a)->bottom = NULL;
	(*stack_b)->cnt = 0;
	(*stack_b)->top = NULL;
	(*stack_b)->bottom = NULL;
}

/* 양방향 링크드리스트 만들기 */

/* parsing 부분 만들기
	과제의 요구사항에 맞춰 입력 예외사항 만들기 */

int	is_sorted(t_stack **stack)
{
	t_node	*temp;

	temp = (*stack)->top;
	while (temp->prev)
	{
		if (temp->num > temp->prev->num)
			break ;
		temp = temp->prev;
	}
	if (temp->num == (*stack)->bottom->num)
		return (1);
	return (0);
}

t_node	*make_node(char *str)
{
	t_node	*return_node;

	return_node = (t_node *)shell_malloc(sizeof(t_node));
	return_node->num = ft_atoll(str);
	return_node->index = 0;
	return_node->next = 0;
	return_node->prev = 0;
	return (return_node);
}

void	parsing(char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**arg;
	t_node	*node;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			return ;
		arg = ft_split(argv[i++], ' ');
		if (arg == 0 || (arg != 0 && arg[0] == 0))
			return (free_split(&arg));
		j = 0;
		while (arg[j])
		{
			dup_check(a, ft_atoll(arg[j]));
			push_bottom(a, make_node(arg[j++]));
		}
		free_split(&arg);
	}
}

void	push_bottom(t_stack **stack, t_node *new)
{
	new->next = 0;
	new->prev = 0;
	if ((*stack)->cnt == 0)
	{
		(*stack)->top = new;
		(*stack)->bottom = new;
		(*stack)->cnt = 1;
		return ;
	}
	(*stack)->bottom->prev = new;
	new->next = (*stack)->bottom;
	(*stack)->bottom = new;
	(*stack)->cnt += 1;
}

void	dup_check(t_stack **stack, int num)
{
	t_node	*node;

	if ((*stack)->cnt == 0)
		return ;
	node = (*stack)->bottom;
	while (node)
	{
		if (node->num == num)
			unix_error("duplicate number");
		node = node->next;
	}
}

void	free_split(char ***nums)
{
	int	i;

	i = 0;
	if (*nums == 0)
		return ;
	while ((*nums)[i])
		free((*nums)[i++]);
	free(*nums);
	*nums = 0;
	return ;
}

int	ft_atoll(char *str)
{
	int			digit;
	int			value_sign;
	long long	value;

	digit = 0;
	value = 0;
	value_sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		value_sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = 10 * value + *str - '0';
		str++;
		digit++;
	}
	value = value * (long long)value_sign;
	if (*str != '\0' || value > 2147483647
		|| value < -2147483648 || digit > 10 || digit == 0)
		unix_error("ft_atoll");
	return ((int)value);
}

/* 커맨드 액션 */
void	push(t_stack **stack, t_node *new)
{
	new->next = 0;
	new->prev = 0;
	if ((*stack)->cnt == 0)
	{
		(*stack)->top = new;
		(*stack)->bottom = new;
		(*stack)->cnt += 1;
		return ;
	}
	new->prev = (*stack)->top;
	(*stack)->top->next = new;
	(*stack)->top = new;
	(*stack)->cnt += 1;
}

t_node	*pop(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->cnt == 0)
		return (0);
	temp = (*stack)->top;
	if ((*stack)->cnt == 1)
	{
		(*stack)->cnt = 0;
		(*stack)->top = 0;
		(*stack)->bottom = 0;
		return (temp);
	}
	(*stack)->top = (*stack)->top->prev;
	(*stack)->top->next = 0;
	(*stack)->cnt -= 1;
	return (temp);
}

void	p(t_stack **to, t_stack **from)
{
	t_node	*node;

	node = pop(from);
	if (node == 0)
		return ;
	push(to, node);
}

void	pa(t_stack **a, t_stack **b)
{
	if ((*b)->cnt <= 0)
		return ;
	p(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if ((*a)->cnt <= 0)
		return ;
	p(b, a);
	write(1, "pb\n", 3);
}

void	swap(t_stack **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if ((*stack)->cnt < 2)
		return ;
	temp1 = (*stack)->top;
	temp2 = temp1->prev;
	temp1->prev = temp2->prev;
	temp2->next = temp1->next;
	if (temp1->prev != NULL)
		temp1->prev->next = temp1;
	if (temp2->next != NULL)
		temp2->next->prev = temp2;
	temp1->next = temp2;
	temp2->prev = temp1;
	(*stack)->top = temp2;
}

void	sa(t_stack **a)
{
	if ((*a)->cnt < 2)
		return ;
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack **b)
{
	if ((*b)->cnt < 2)
		return ;
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}

void	r(t_stack **stack)
{
	t_node	*new_bottom;
	t_node	*new_top;

	new_bottom = (*stack)->top;
	new_top = (*stack)->top->prev;
	new_top->next = 0;
	new_bottom->next = (*stack)->bottom;
	new_bottom->prev = 0;
	new_bottom->next->prev = new_bottom;
	(*stack)->bottom = new_bottom;
	(*stack)->top = new_top;
}

void	ra(t_stack **stack)
{
	write(1, "ra\n", 3);
	r(stack);
}

void	rb(t_stack **stack)
{
	write(1, "rb\n", 3);
	r(stack);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	r(a);
	r(b);
}

void	rev_r(t_stack **stack)
{
	t_node	*new_bottom;
	t_node	*new_top;

	new_top = (*stack)->bottom;
	new_bottom = (*stack)->bottom->next;
	new_top->next = 0;
	new_top->prev = (*stack)->top;
	new_top->prev->next = new_top;
	new_bottom->prev = 0;
	(*stack)->bottom = new_bottom;
	(*stack)->top = new_top;
}

void	rra(t_stack **stack)
{
	write(1, "rra\n", 4);
	rev_r(stack);
}

void	rrb(t_stack **stack)
{
	write(1, "rrb\n", 4);
	rev_r(stack);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rev_r(a);
	rev_r(b);
}

/* 커맨드 링크드리스트 만들기 */

/* 커맨드 리스트 저장 및 출력 */

/* small case 정렬 로직 구현하기 */

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = (*a)->cnt;
	if (size <= 1)
		return ;
	if (size == 2)
		sort2(a, b);
	if (size == 3)
		sort3(a, b);
	if (size == 4)
		sort4(a, b);
	if (size == 5)
		sort5(a, b);
}

void	sort2(t_stack **a, t_stack **b)
{
	if ((*a)->bottom->num < (*a)->top->num)
		sa(a);
}

void	sort3(t_stack **a, t_stack **b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->top->num;
	n2 = (*a)->top->prev->num;
	n3 = (*a)->top->prev->prev->num;
	if (is_sorted(a))
		return ;
	else if (n3 < n1 && n2 < n3)
		ra(a);
	else if (n1 < n2 && n3 < n1)
		rra(a);
	else
		sort3_1(a, b);
}

void	sort3_1(t_stack **a, t_stack **b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->top->num;
	n2 = (*a)->top->prev->num;
	n3 = (*a)->top->prev->prev->num;
	sa(a);
	if (n2 < n1 && n3 < n2)
		rra(a);
	if (n3 < n2 && n1 < n3)
		ra(a);
}

void	sort4(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort3(a, b);
	pa(a, b);
	sort4_1(a, b);
}

void	sort4_1(t_stack **a, t_stack **b)
{
	if ((*a)->top->num > (*a)->bottom->num)
		ra(a);
	else if ((*a)->top->num > (*a)->bottom->next->num)
	{
		rra(a);
		sa(a);
		ra(a);
		ra(a);
	}
	else if ((*a)->top->num > (*a)->bottom->next->next->num)
		sa(a);
}

void	sort5(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	while ((*a)->cnt > 3)
	{
		if ((*a)->top->index == 1 || (*a)->top->index == 2)
			pb(a, b);
		else
			ra(a);
	}
	sort3(a, b);
	if ((*b)->top->index == 1)
		sb(b);
	pa(a, b);
	pa(a, b);
}

/* 정렬 재귀 로직 구현하기 */

void	indexing(t_stack **a)
{
	int		i;
	int		*index_arr;
	t_node	*node;

	i = 0;
	index_arr = (int *)shell_malloc(sizeof(int) * (*a)->cnt);
	node = (*a)->bottom;
	while (i < (*a)->cnt)
	{
		index_arr[i] = node->num;
		node = node->next;
		i++;
	}
	index_sort(index_arr, (*a)->cnt);
	while (i > 0)
	{
		node = (*a)->bottom;
		while (index_arr[i - 1] != node->num)
			node = node->next;
		node->index = i;
		i--;
	}
	free(index_arr);
}

void	index_sort(int *index_arr, int arr_size)
{
	int	i;
	int	j;
	int	min_index;
	int	temp;

	i = 0;
	while (i < arr_size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < arr_size)
		{
			if (index_arr[j] < index_arr[min_index])
				min_index = j;
			j++;
		}
		temp = index_arr[min_index];
		index_arr[min_index] = index_arr[i];
		index_arr[i] = temp;
		i++;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	if ((*a)->cnt < 100)
		a_to_b(a, b, 3);
	else if ((*a)->cnt < 250)
		a_to_b(a, b, 11);
	else if ((*a)->cnt < 700)
		a_to_b(a, b, 25);
	else if ((*a)->cnt < 1500)
		a_to_b(a, b, 50);
	else
		a_to_b(a, b, 100);
	b_to_a(a, b);
}

void	a_to_b(t_stack **a, t_stack **b, int chunk_num)
{
	int	i;
	int	pivot;

	if (chunk_num == 0)
		return ;
	pivot = find_pivot(a, chunk_num);
	while ((*a)->cnt > 0 && find_min(a) <= pivot)
	{
		if ((*a)->top->index <= pivot)
			pb(a, b);
		else
			ra(a);
	}
	if ((*a)->cnt && is_sorted(a) != 1)
		a_to_b(a, b, chunk_num - 1);
}

void	b_to_a(t_stack **a, t_stack **b)
{
	int	rb_cnt;
	int	rrb_cnt;

	while ((*b)->cnt)
	{
		count_rotate(b, &rb_cnt, &rrb_cnt);
		if ((*b)->top->index == find_max(b))
			pa(a, b);
		else
		{
			if (rb_cnt < rrb_cnt)
				while (rb_cnt--)
					rb(b);
			else
				while (rrb_cnt--)
					rrb(b);
		}
	}
}

void	count_rotate(t_stack **b, int *rb_cnt, int *rrb_cnt)
{
	int		max_index;
	t_node	*node;

	*rb_cnt = 0;
	*rrb_cnt = 0;
	max_index = find_max(b);
	node = (*b)->top;
	while (node->index != max_index)
	{
		(*rb_cnt)++;
		node = node->prev;
	}
	if ((*b)->top->index != max_index)
		(*rrb_cnt) = (*b)->cnt - (*rb_cnt) + 1;
}

int	find_pivot(t_stack **stack, int chunk_num)
{
	int	pivot;

	pivot = (*stack)->cnt / chunk_num + find_min(stack);
	return (pivot);
}

int	find_min(t_stack **stack)
{
	int		min_index;
	t_node	*node;

	node = (*stack)->top;
	min_index = node->index;
	while (node->prev)
	{
		node = node->prev;
		if (min_index > node->index)
			min_index = node->index;
	}
	return (min_index);
}

int	find_max(t_stack **stack)
{
	int		max_index;
	t_node	*node;

	node = (*stack)->top;
	max_index = node->index;
	while (node->prev)
	{
		node = node->prev;
		if (max_index < node->index)
			max_index = node->index;
	}
	return (max_index);
}

/* 검토 */

void	free_stack(t_stack **a, t_stack **b)
{
	t_node	*node;
	t_node	*temp;

	if (a != 0 && *a != 0)
	{
		node = (*a)->bottom;
		while (node)
		{
			temp = node->next;
			free(node);
			node = temp;
		}
	}
	free(*a);
	if (b != 0 && *b != 0)
	{
		node = (*b)->bottom;
		while (node)
		{
			temp = node->next;
			free(node);
			node = temp;
		}
	}
	free(*b);
}
