/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_puts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 14:31:54 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 14:38:36 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

/*
** TODO: Replace printf with homemade ft_printf
*/

void	int_puts(t_int *ptr)
{
	if (ptr->inttype == T_INT)
		printf("%ld", *ptr->val->intp);
}
