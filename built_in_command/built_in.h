/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:15:28 by okaname           #+#    #+#             */
/*   Updated: 2025/03/24 20:54:41 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "../utils/utils.h"
# include <stdlib.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_mini
{
	t_env			*var_env;
	int				status;
}					t_mini;

void				ft_exit(char **strs);
int					ft_pwd(void);
void				print_sorted_env(t_env *head);
void				print_list(t_env *head);
int					ft_pwd(void);

#endif