/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 14:27:26 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 14:31:17 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

/*
** Allocates an int object. Int objects are not naturally GC-d
** and have to be connected to a lvar at all times.
** 1
** Ints have no value indicating they are uninitialised. The requesting
** function has to handle initialisation immediately.
*/

t_int	*int_new(void)
{
	t_int	*ptr;

	if (!(ptr = malloc(sizeof(t_int))))
		return (NULL);
	if (!(ptr->val = malloc(sizeof(t_intp))))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
