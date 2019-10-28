/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_hyndred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:18:29 by cormund           #+#    #+#             */
/*   Updated: 2019/10/28 13:11:48 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		throwing_in_stack_b(t_ps *ps, t_stack **a, t_stack **b,\
															t_max_min m)
{
	while (SIZE_B < m.mid)
	{
		if (TOP_A <= m.mid)
			ps_push(ps, b, a);
		else
			ps_rotate(ps, a);
		if (TOP_B == m.min && m.min < m.pmax) // && TOP_B == m.min < m.mid / 2
		{
			ps_rotate(ps, b);
			++m.min;
		}
	}
	while (SIZE_A > 3)
	{
		if (TOP_A <= m.max)
			ps_push(ps, b, a);
		else
			ps_rotate(ps, a);
		if (SIZE_A > 4 && (TOP_B == m.max || (TOP_B == m.pmax && ((m.max - m.pmax) == 1))))
		{
			if (TOP_B == m.max)
				--m.max;
			--m.pmax;
			ps_rotate(ps, b);
		}
	}
}

// (TOP_B == m.max || TOP_B == m.pmax) && SIZE_A > 4

static int		depth_max_in_stack(t_stack *st, t_max_min m)
{
	t_stack		*tmp;
	int			depth_rotate;
	int			depth_reverse;

	tmp = st;
	depth_rotate = 0;
	while (tmp->i != m.max && tmp->i != m.pmax && tmp->next != st)
	{
		++depth_rotate;
		tmp = tmp->next;
	}
	tmp = st->prev;
	depth_reverse = 1;
	while (tmp->i != m.max && tmp->i != m.pmax && tmp->prev != st)
	{
		++depth_reverse;
		tmp = tmp->prev;
	}
	return (depth_reverse > depth_rotate ? 0 : 1);
}

static int		need_to_hide(int top_b, t_ps *ps, t_max_min m)
{
	if (top_b > ps->a->prev->i || ps->a->prev->i > m.max)
		return (1);
	if ((ps->a->prev->i - top_b) == 1 && (ps->a->prev->prev->i - ps->a->prev->i) != 1)
		return (1);
	return (0);
}

static void		ascend_max_pmax_min(t_ps *ps, t_stack **b, t_max_min m)
{
	int			reverse;

	reverse = depth_max_in_stack(*b, m);
	if (reverse)
		while (TOP_B != m.max && TOP_B != m.pmax && !is_neighbour(TOP_B, ps, m))
			ps_reverse(ps, b);
	else
		while (TOP_B != m.max && TOP_B != m.pmax && !is_neighbour(TOP_B, ps, m))
			ps_rotate(ps, b);
}

void			sort_first_hundred(t_ps *ps, t_stack **a, t_stack **b)
{
	t_max_min	m;

	m.max = PS_MAX_INDEX_IN_STACK_B;
	m.pmax = PS_PREVIOUS_MAX;
	m.min = PS_FIRST_INDEX;
	m.mid = SIZE_A / 2;
	throwing_in_stack_b(ps, a, b, m);
	sort_three_elem(ps, &ps->a, 3);
	while (m.mid)
	{
		ascend_max_pmax_min(ps, b, m);
		ps_push(ps, a, b);
		--m.mid;
		if ()
	}


	// 	if (TOP_A == m.max)
	// 	{
	// 		--m.max;
	// 		--m.pmax;
	// 	}
	// 	else if (TOP_A == m.min && m.min < m.pmax)
	// 	{
	// 		ps_rotate(ps, a);
	// 		++m.min;
	// 		if (SIZE_B > 2 && TOP_B != m.max && (SECOND_B == m.max || SECOND_B == m.pmax || SECOND_B == m.min))
	// 			ps_rotate(ps, b);
	// 	}
	// 	if (TOP_A > SECOND_A)
	// 	{
	// 		--m.max;
	// 		--m.pmax;
	// 		ps_swap(ps, a);
	// 		if (SIZE_B > 2 && TOP_B != m.max && (SECOND_B == m.max || SECOND_B == m.pmax || SECOND_B == m.min))
	// 			ps_swap(ps, b);
	// 	}
	// }
	// while (--m.min)
	// 	ps_reverse(ps, a);