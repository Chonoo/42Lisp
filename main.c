/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 23:57:33 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 16:36:44 by jbyttner         ###   ########.fr       */
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
	if (errn)
		printf("Error");
	//if (!errn)
	//	lvar_puts(our_int);
	return (0);
}
