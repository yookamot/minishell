/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:55:26 by yookamot          #+#    #+#             */
/*   Updated: 2025/04/16 19:26:39 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parser_error(t_tokenset *tokenset, char *value)
{
	write(2, "bash: syntax error near unexpected token `", 42);
	if (!ft_strcmp(value, "\n"))
		write(2, "newline", 7);
	else
		write(2, value, ft_strlen(value));
	write(2, "'\n", 2);
	free_tokenset(tokenset, SUCCESS);
	return (FAILED);
}
