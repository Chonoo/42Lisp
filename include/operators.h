/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 08:13:36 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 17:35:24 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATORS_H
# define FT_OPERATORS_H

/*
** Integer Functions
*/

int			ft_add_int(int a, int b);

int			ft_sub_int(int a, int b);

int			ft_mul_int(int a, int b);

int			ft_div_int(int a, int b);

int			ft_mod_int(int a, int b);

/*
** Utility Functions
*/

int			is_operator(char *str);

int			op_prio(char *str);

int			operator_precedence(char *s1, char *s2);

#endif
