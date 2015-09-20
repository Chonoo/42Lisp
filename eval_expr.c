/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 00:43:10 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/20 04:14:59 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double_list.h"
#include "eval_expr.h"
#include "ft_opp.h"
#include "operators.h"
#include <stdlib.h>

void	run_op(int **res, char *s2, char *s1, char *op)
{
	int		a;
	int		b;
	int		i;

	a = ft_atoi(s1);
	b = ft_atoi(s2);
	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(op, g_opptab[i].op) == 0)
			**res = g_opptab[i].f(a, b);
		i++;
	}
}

void	execute_op_simple(t_listd **output, int **res)
{
	char	*val;
	t_listd	**numbers;

	if (!ft_listd_peek(output))
	{
		*res = 0;
		return ;
	}
	numbers = malloc(sizeof(t_listd*));
	numbers[0] = 0;
	while (ft_listd_peek(output))
	{
		val = ft_listd_pop(output);
		if (is_operator(val))
		{
			run_op(res, ft_listd_pop(numbers), ft_listd_pop(numbers), val);
			ft_listd_push_front(ft_itoa(**res), numbers);
		}
		else
			ft_listd_push_front(val, numbers);
	}
	if (ft_listd_peek(numbers))
		**res = ft_atoi(ft_listd_pop(numbers));
}

int		eval_expr(char *str)
{
	t_listd	**input;
	t_listd	**output;
	int		**res;

	input = malloc(sizeof(t_listd*));
	input[0] = 0;
	res = malloc(sizeof(int*));
	*res = malloc(sizeof(int));
	ft_read_to_queue(str, input);
	output = shunting_yard(input);
	execute_op_simple(output, res);
	if (*res == 0)
		return (0);
	return (**res);
}
