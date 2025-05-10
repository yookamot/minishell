/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:26:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/05/01 22:01:39 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

static int	check_input_update(t_tokenset *tokenset, int i, int key)
{
	if (key == FRONT || (key == BACK && tokenset->token[i + 1]->type != 10
			&& tokenset->token[i + 1]->type != 7))
		return (FAILED);
	else
		return (SUCCESS);
}

static void	reset_input_ex(t_tokenset *tokenset, int i, int j)
{
	size_t	len;
	char	*pre;
	char	*inner;
	char	*post;
	char	*tmp;

	len = ft_strlen(tokenset->input);
	pre = ft_substr(tokenset->input, 0, j);
	inner = ft_substr(tokenset->input, j + 2, ft_strlen(tokenset->token[i
				+ 2]->value));
	post = ft_substr(tokenset->input, j + 2 + ft_strlen(tokenset->token[i
				+ 2]->value), len - (j + 2 + ft_strlen(tokenset->token[i
					+ 2]->value)));
	tmp = ft_strjoin(pre, inner);
	free(pre);
	free(inner);
	pre = ft_strjoin(tmp, post);
	free(tmp);
	free(post);
	free(tokenset->input);
	tokenset->input = pre;
}

// tokenのほうでquoteを消すのに応じて、inputのquoteを削除
void	reset_input(t_tokenset *tokenset, int i, int j, int key)
{
	size_t	len;
	char	*pre;
	char	*inner;
	char	*post;
	char	*tmp;

	if (!check_input_update(tokenset, i, key))
		return ;
	if (tokenset->input[j] == tokenset->input[j + 1])
		return (reset_input_ex(tokenset, i, j));
	len = ft_strlen(tokenset->input);
	pre = ft_substr(tokenset->input, 0, j);
	inner = ft_substr(tokenset->input, j + 1, ft_strlen(tokenset->token[i
				+ 1]->value));
	post = ft_substr(tokenset->input, j + 2 + ft_strlen(tokenset->token[i
				+ 1]->value), len - (j + 2 + ft_strlen(tokenset->token[i
					+ 1]->value)));
	tmp = ft_strjoin(pre, inner);
	free(pre);
	free(inner);
	pre = ft_strjoin(tmp, post);
	free(tmp);
	free(post);
	free(tokenset->input);
	tokenset->input = pre;
}
