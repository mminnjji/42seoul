/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:17:52 by man               #+#    #+#             */
/*   Updated: 2023/10/11 15:40:48 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_arg
{
	int		fd_input;
	int		fd_output;
	pid_t	pid;
	char	**cmd[2];
	char	*r_cmd[2];
	char	**path;
	int		fd[2];
}	t_arg;

void	print_error(void);
char	**get_path(char *envp[]);
char	*get_cmd(char **path, char *cmd);
void	run_cmd(char *cmd, char *envp[], t_arg *p, int idx);
void	cmd_check(char *envp[], t_arg *p, int idx);

#endif
