/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_cons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:39:13 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 18:52:25 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

t_llst	*llst_cons(t_lvar *a, t_llst *b, int *errn)
{
	t_llst	*res;

	if (!(res = llst_new()))
	{
		error_raise(errn, ERR_NO_MEM);
		return (NULL);
	}
	res->val = a;
	res->next = b;
	GC_INC(a);
	return (res);
}
