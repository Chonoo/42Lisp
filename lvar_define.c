/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvar_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 20:57:46 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/17 23:19:33 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

/*
** This is a parser-level function. It is hard-coded and not included in
** the global namespace.
*/

static inline void	lvar_define_sysllst(t_ns *ns, t_sysstr str, t_sysllst *llst,
		int *errn)
{
	error_raise(errn, ERR_NOT_IMPLEMENTED);
}

static inline void	lvar_define_fn(t_ns *ns, t_fn *fn, t_lvar *var,
		int *errn)
{
	error_raise(errn, ERR_NOT_IMPLEMENTED);
}

static inline void	lvar_define_sysstr(t_ns *ns, t_sysstr s1, t_sysstr s2,
		int *errn)
{
	t_lvar	*res;

	if (sysstr_is_lvar(s2))
	{
		res = ns_get(ns, s2, errn);
	} // Todo: add llst harness here
	else if (sysstr_is_num(s2))
		res = lvar_new_num(s2, errn);
	else // TODO: Add harness to load valid sysllst result
		error_raise(errn, ERR_NOT_IMPLEMENTED);
	if (*errn)
	{
		error_print_stack("Defining from sysstr");
		return ;
	}
	ns_add(ns, s1, res, errn);
	if (*errn)
		error_print_stack("");
}

void	lvar_define(t_ns *ns, t_lvar *v1, t_lvar *v2, int *errn)
{
	if (ltype_is_sysstr(v1))
	{
		if (ltype_is_sysstr(v2))
			lvar_define_sysstr(ns, v1->val->sysstrp,
				v2->val->sysstrp, errn);
		else if (ltype_is_sysllst(v2))
			lvar_define_sysllst(ns, v1->val->sysstrp,
				v2->val->sysllstp, errn);
	}
	else if(ltype_is_sysllst(v1))
		lvar_define_fn(ns, v1->val->fnp, v2, errn);
	else
	{
		error_raise(errn, ERR_NOT_IMPLEMENTED);
		return ;
	}
	if (*errn)
		error_print_stack("Define (parse function)");
}
