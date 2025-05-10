/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:30:13 by yookamot          #+#    #+#             */
/*   Updated: 2025/04/29 22:24:43 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

//各行に含まれる単語数のカウント
static int	count_word(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	count++;
	return (count);
}

//行数を削減してくれてありがとう
static void	gyousuu_sakugen_kun(t_tokenlist *tokenlist, char **lines,
		char **array, t_token *token)
{
	if (!token)
		free_tokenlist(tokenlist, lines, array, FAILED);
}

//各行をトークン化する（valueの値）
static void	tokenize_command(char *command, t_tokenlist *tokenlist, int i,
		char **lines)
{
	char	**array;
	int		j;

	array = ft_split_custom(command, tokenlist, i);
	if (!array)
		return (tokenlist->token[i] = NULL, free_tokenlist(tokenlist, lines,
				NULL, FAILED));
	tokenlist->token_count[i] = count_word(array);
	tokenlist->token[i] = (t_token **)malloc(sizeof(t_token *)
			* tokenlist->token_count[i]);
	if (!tokenlist->token[i])
		free_tokenlist(tokenlist, lines, array, FAILED);
	j = 0;
	while (j < tokenlist->token_count[i] - 1)
	{
		tokenlist->token[i][j] = (t_token *)malloc(sizeof(t_token));
		gyousuu_sakugen_kun(tokenlist, lines, array, tokenlist->token[i][j]);
		init_token(tokenlist->token[i][j], array[j], tokenlist);
		j++;
	}
	tokenlist->token[i][j] = (t_token *)malloc(sizeof(t_token));
	gyousuu_sakugen_kun(tokenlist, lines, array, tokenlist->token[i][j]);
	init_token(tokenlist->token[i][j], NULL, tokenlist);
	free_array(array);
}

//行数のカウント
static int	count_line(char *input)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

//各行をトークン化する
void	get_tokens(t_tokenlist *tokenlist)
{
	char	**array;
	int		i;

	tokenlist->set_count = count_line(tokenlist->input);
	array = ft_split(tokenlist->input, '\n');
	if (!array)
		return (tokenlist->token = NULL, free_tokenlist(tokenlist, NULL, NULL,
				FAILED));
	tokenlist->token = (t_token ***)malloc(sizeof(t_token **)
			* tokenlist->set_count);
	if (!tokenlist->token)
		free_tokenlist(tokenlist, array, NULL, FAILED);
	tokenlist->token_count = (int *)malloc(sizeof(int) * (tokenlist->set_count
				+ 1));
	if (!tokenlist->token_count)
		free_tokenlist(tokenlist, array, NULL, FAILED);
	tokenlist->token_count[tokenlist->set_count] = 0;
	i = 0;
	while (i < tokenlist->set_count)
	{
		tokenize_command(array[i], tokenlist, i, array);
		i++;
	}
	return (free_array(array));
}
