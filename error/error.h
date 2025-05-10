/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:55:23 by okaname           #+#    #+#             */
/*   Updated: 2025/04/25 21:59:13 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../struct.h"
# include "../utils/utils.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	error_arg(void);
void	error_pipe(void);
void	error_infile_invalid(char *infile);
void	error_infile_open_failed(char *infile);
void	error_infile_close_failed(void);
void	error_redirect(void);
void	error_malloc(char **arr1, char **arr2);
void	error_command1(char *cmd_parts);
void	error_execve1(void);
void	error_fork1(void);
void	error_outfile_invalid(pid_t pid1, char *outfile);
void	error_outfile_open_failed(pid_t pid1, char *outfile);
void	error_outfile_close_failed(pid_t pid1);
void	error_command2(pid_t pid1, char **cmd_parts);
void	error_execve2(pid_t pid1, char *full_path, char **cmd_args);
void	error_fork2(pid_t pid1);
void	error_redirect_out(pid_t pid1);
void	error_command1_directory(char **cmd_parts);
void	error_command2_directory(pid_t pid1, char **cmd_parts);
void	error_command1_nonexistent(char **cmd_parts);
void	error_command2_nonexistent(pid_t pid1, char **cmd_parts);

void	error_accese(char *file);
void	error_open(char *file);
void	error_close(void);
void	error_fork(t_mini *mini, t_tokenset *tokenset, int *pid);
void	error_malloc1(t_mini *mini, t_tokenset *tokenset);

#endif