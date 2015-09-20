/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 23:35:10 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/20 03:56:51 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_EXPR_H
# define FT_EVAL_EXPR_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_atoi.h"
# include "ft_double_list.h"
# include "ft_strutil.h"
# include "operator_util.h"

int		eval_expr(char *str);

#endif
