/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 17:58:32 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 18:07:58 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft_strutil.h"
# include "ft_o_list.h"
# include "operators.h"

void		ft_read_to_queue(char *str, t_o_list **input);

void		shunting_yard_simple(t_o_list **input,
			t_o_list **output, t_o_list **ops);

t_o_list	**shunting_yard(t_o_list **input);

#endif
