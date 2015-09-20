/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 00:10:43 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/20 00:12:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATOR_UTIL_H
# define FT_OPERATOR_UTIL_H

int		is_operator(char *str);

int		op_prio(char *str);

int		operator_precedence(char *s1, char *s2);

#endif
