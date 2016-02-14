/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvar_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 23:48:17 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 13:41:27 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

/*
** Creates a new lvar on the heap. This variable is GC-managed.
** We set refcnt to 1 to avoid immediate garbage cleaning.
** Set to zero to mark for destruction.
*/

t_lvar			*lvar_new(void)
{
	t_lvar		*res;

	if (!(res = malloc(sizeof(t_lvar))))
		return (NULL);
	if (!(res->val = malloc(sizeof(t_lptr))))
	{
		free(res);
		return (NULL);
	}
	res->type = T_NULLP;
	//res->next = 0;
	res->gc_next = 0;
	res->refcnt = 1;
	gc_add(res);
	return (res);
}
