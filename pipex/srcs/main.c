/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: man <man@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:18:24 by man               #+#    #+#             */
/*   Updated: 2023/10/21 12:45:35 by man              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent(char *argv[], char *envp[], t_arg *p)
{
	close(p->fd[1]);
	p->fd_output = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->fd_output == -1)
		print_error();
	dup2(p->fd[0], STDIN_FILENO);
	dup2(p->fd_output, STDOUT_FILENO);
	run_cmd(argv[3], envp, p, 0);
}

void	child(char *argv[], char *envp[], t_arg *p)
{
	close(p->fd[0]);
	p->fd_input = open(argv[1], O_RDONLY);
	if (p->fd_input == -1)
	{
		write(2, "pipex: ", 7);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory\n", 28);
		exit(EXIT_FAILURE);
	}
	dup2(p->fd[1], STDOUT_FILENO);
	dup2(p->fd_input, STDIN_FILENO);
	close(p->fd[0]);
	run_cmd(argv[2], envp, p, 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;
	int		idx;

	idx = -1;
	arg.path = NULL;
	if (argc != 5)
	{
		perror("Error: Bad arguments\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (pipe(arg.fd) == -1)
			print_error();
		arg.pid = fork();
		if (arg.pid < 0)
			print_error();
		if (arg.pid == 0)
			child(argv, envp, &arg);
		waitpid(arg.pid, NULL, WNOHANG);
		parent(argv, envp, &arg);
	}
	return (0);
}
