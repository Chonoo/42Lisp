/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 23:57:33 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 18:50:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

int		main(void)
{
	t_lvar	*i1;
	t_lvar	*i2;
	t_lvar	*i3;
	t_nshash	*global;
	int		errn;

	errn = 0;
	global = ns_global_new(&errn);
	if (errn)
		exit(0);
	i1 = lvar_new_int("12", &errn);
	if (errn)
		exit(0);
	i2 = lvar_new_int("55", &errn);
	if ((errn))
		exit(0);
	global->add(global, "i1", i1, &errn);
	if (errn)
		exit(0);
	global->add(global, "i2", i2, &errn);
	if (errn)
		exit(0);
	i3 = lvar_add(global->get(global, "i1", &errn),
			global->get(global, "i2", &errn), &errn);
	if (!(errn))
		lvar_puts(i3);
	t_lvar *l1 = lvar_new_llst(i3, &errn);
	if (errn)
		exit(0);
	l1 = lvar_cons(i2, l1, &errn);
	l1 = lvar_cons(i2, l1, &errn);
	if (errn)
		exit(0);
	lvar_puts(l1);
	//if (!errn)
	//	lvar_puts(our_int);
	return (0);
}
