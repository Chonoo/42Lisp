/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nshash_new_bucket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:17:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 16:20:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

t_nshi	*nshash_new_bucket(char *str, t_lvar *var)
{
	t_nshi	*bucket;

	if (!(bucket = malloc(sizeof(t_nshi))))
		return (NULL);
	if (!(bucket->name = ft_strdup(str)))
	{
		free(bucket);
		return (NULL);
	}
	bucket->next = 0;
	bucket->value = var;
	return (bucket);
}
