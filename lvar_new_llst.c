/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvar_new_llst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:18:06 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 18:25:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

t_lvar		*lvar_new_llst(t_lvar *var, int *errn)
{
	t_llst	*tmp;
	t_lvar	*res;

	if (!(tmp = llst_new()))
	{
		error_raise(errn, ERR_NO_MEM);
		return (NULL);
	}
	if (!(res = lvar_new()))
	{
		error_raise(errn, ERR_NO_MEM);
		free(tmp);
		return (NULL);
	}
	res->val->llstp = tmp;
	res->type = T_LLSTP;
	tmp->val = var;
	return (res);
}
