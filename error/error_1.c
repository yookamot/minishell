/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:37:54 by yookamot          #+#    #+#             */
/*   Updated: 2025/03/06 20:49:52 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_arg(void)
{
	write(2, "Error: Invalid Arguments\n", 26);
	exit(1);
}

void	error_pipe(void)
{
	perror("bash: pipe");
	exit(1);
}

void	error_infile_invalid(char *infile)
{
	write(2, "bash: ", 6);
	perror(infile);
}

void	error_infile_open_failed(char *infile)
{
	write(2, "bash: ", 6);
	perror(infile);
}

void	error_infile_close_failed(void)
{
	perror("bash: close");
}
