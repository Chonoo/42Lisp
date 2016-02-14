/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 19:09:48 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 19:45:00 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"
#define SYS_SETUP_NUM_FNS (sizeof(t_sysfn) * 4);

/*
** Takes a namespace and adds system functions (cons, car, + ...) to it.
*/

static inline t_lvar	*sys_setup_fn(int varcnt, t_lvar *(*fn)())
{
	t_sysfn	*tmp;
	t_lvar	*res;

	if (!(tmp = malloc(sizeof(t_sysfn))))
		return (NULL);
	if (!(res = lvar_new()))
	{
		free(tmp);
		return (NULL);
	}
	tmp->fn = fn;
	tmp->varcnt = varcnt;
	res->val->sysfnp = tmp;
	res->type = T_SYSFNP;
	return (res);
}

static inline int	sys_setup_add(t_nshash *global, char *str,
		t_lvar *(*fn)(), int varcnt)
{
	t_lvar	*fnvar;
	int		errn;

	if (!(fnvar = sys_setup_fn(varcnt, fn)))
		return (-1);
	global->add(global, str, fnvar, &errn);
	if (errn)
		return (-1);
	else
		return (1);
}

int		sys_setup(t_nshash *global)
{
	if (sys_setup_add(global, "cons", lvar_cons, 2) == -1)
		return (-1);
	if (sys_setup_add(global, "+", lvar_add, 2) == -1)
		return (-1);
	return (1);
}
