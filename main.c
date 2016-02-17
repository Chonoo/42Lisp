/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 23:57:33 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/17 23:10:33 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

int		main(void)
{
/*	t_lvar	*i1;
	t_lvar	*i2;
	t_lvar	*i3;
	t_nshash	*global;
	int		errn;

	errn = 0;
	global = ns_global_new(&errn);
	if (sys_setup(global) == -1)
		exit(1);
	lvar_define(global, "int1", "12", &errn);
	if (errn)
		exit(10);
	lvar_define(global, "int2", "44", &errn);
	if (errn)
		exit(11);*/
	/*if (errn)
		exit(2);
	i1 = lvar_new_int("12", &errn);
	if (errn)
		exit(3);
	i2 = lvar_new_int("55", &errn);
	if ((errn))
		exit(4);
	global->add(global, "i1", i1, &errn);
	if (errn)
		exit(5);
	global->add(global, "i2", i2, &errn);
	if (errn)
		exit(6);*/
	//i3 = lvar_add(global->get(global, "i1", &errn),
	//		global->get(global, "i2", &errn), &errn);
	/*i3 = global->get(global, "+", &errn)->val->sysfnp->fn(global->get(global, "i1", &errn),
			global->get(global, "i2", &errn), &errn);

	//if (!(errn))
	//	lvar_puts(i3);
	t_lvar *l1 = lvar_new_llst(i3, &errn);
	if (errn)
		exit(0);
	l1 = lvar_cons(i2, l1, &errn);
	l1 = lvar_cons(i2, l1, &errn);
	if (errn)
		exit(0);
	lvar_puts(l1);*/
	//if (!errn)
	//	lvar_puts(our_int);
	return (0);
}
