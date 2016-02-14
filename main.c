/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 23:57:33 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 15:17:35 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

int		main(void)
{
	t_lvar	*i1;
	t_lvar	*i2;
	t_lvar	*i3;
	int		errn;

	errn = 0;
	i1 = lvar_new_int("12", &errn);
	if (!(errn))
	{
		i2 = lvar_new_int("55", &errn);
		if (!(errn))
		{
			i3 = lvar_add(i1, i2, &errn);
			if (!(errn))
				lvar_puts(i3);
		}
	}
	if (errn)
		printf("Error");
	//if (!errn)
	//	lvar_puts(our_int);
	return (0);
}
