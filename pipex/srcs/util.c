/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:18:40 by man               #+#    #+#             */
/*   Updated: 2023/10/21 12:55:02 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	**get_path(char *envp[])
{
	char	*path;

	if (!envp)
		print_error();
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	*get_cmd(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*new_cmd;
	char	*tmp;

	i = 0;
	fd = 0;
	new_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], new_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(new_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(new_cmd);
	return (NULL);
}

void	cmd_check(char *envp[], t_arg *p, int idx)
{
	if (p->path == NULL)
		p->path = get_path(envp);
	p->r_cmd[idx] = get_cmd(p->path, p->cmd[idx][0]);
	if (!p->r_cmd[idx])
	{
		write(2, "pipex: ", 7);
		write(2, p->cmd[idx][0], ft_strlen(p->cmd[idx][0]));
		write(2, ": command not found\n", 20);
		exit(127);
	}
}

void	run_cmd(char *cmd, char *envp[], t_arg *p, int idx)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != ' ')
			flag = 1;
		i++;
	}
	if (!flag)
	{
		write(2, "pipex: : command not found\n", 27);
		exit(127);
	}
	p->cmd[idx] = ft_split(cmd, ' ');
	if (p->cmd[idx] == NULL)
		print_error();
	cmd_check(envp, p, idx);
	if (execve(p->r_cmd[idx], p->cmd[idx], envp) == -1)
		print_error();
}
