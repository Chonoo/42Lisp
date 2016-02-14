/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvar_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 00:57:07 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 18:16:42 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

static inline int		t_lvar_num_add(t_lvar *res, t_lvar *a,
		t_lvar *b)
{
	if (a->type == T_INTP && b->type == T_INTP)
	{
		if (!(res->val->intp = int_add(a->val->intp, b->val->intp)))
			return (-1);
		res->type = T_INTP;
	}
	return (1);
}

static inline t_lvar	*lvar_add_error(t_lvar *res, int *errn, int errint)
{
	GC_DEC(res);
	error_raise(errn, errint);
	error_print_stack("+ (system function)");
	return (NULL);
}

t_lvar					*lvar_add(t_lvar *a, t_lvar *b, int *errn)
{
	t_lvar	*res;

	if (!(res = lvar_new()))
		return (0);
	if (ltype_is_num(a) && ltype_is_num(b))
	{
		if (t_lvar_num_add(res, a, b) == -1)
			return (lvar_add_error(res, errn, ERR_NO_MEM));
		res->type = T_INTP;
	}
	else
		return (lvar_add_error(res, errn, ERR_WRONG_TYPE));
	return (res);
}
