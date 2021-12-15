/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1mthe0wl </var/spool/mail/evil>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:55:45 by 1mthe0wl          #+#    #+#             */
/*   Updated: 2021/12/15 15:57:09 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*ft_trim(char *str)
{
	char *ret;

	ret = ft_strtrim(str, " ");
	free(str);
	return (ret);
}

int	pipe_counter(char *cmdline)
{
	int	c_pipes;
	char *str;

	c_pipes = 0;
	str = ft_strchr(cmdline, '|');
	while (str != NULL)
	{
		c_pipes++;
		str++;
		str = ft_strchr(str, '|');
	}
	return (c_pipes);
}

void	tokenizing(t_shell *shell)
{
	int		i;
	int		check_len;
//	int		j;

	i = 0;
//	j = 0;
	check_len = 0;
	//printf("%s\n", shell->cmdline);
	//str = ft_strchr(shell->cmdline);
	shell->n_pipes = pipe_counter(shell->cmdline);
	//printf("cmdline: %s\npipes number: %d\n\n", shell->cmdline, shell->n_pipes);
	if (shell->n_pipes)
	{
		shell->tokens = ft_split(shell->cmdline, '|');
		while (shell->cmdline[check_len])
			check_len++;
		//printf("check_len : %d\n", check_len);
		if (check_len <= shell->n_pipes)
			printf("minishell: syntax error near unexpected token `%s'\n", shell->cmdline);
		//printf("tokens:\n 1: %s\n 2: %s\n", shell->tokens[0], shell->tokens[1]);
		while (i < shell->n_pipes && shell->n_pipes > check_len)
		{
			shell->tokens[i] = ft_trim(shell->tokens[i]);
			//printf("tokens[i]%s\n", shell->tokens[i]);
			//shell->cmds[i] = ft_split(shell->tokens[i], ' ');
			//printf("cmds: %s\n", shell->cmds[i]);
			check_len++;
			i++;
		}
	}
	else
	{
		i = 0;
		shell->tokens = ft_split(shell->cmdline, ' ');
		/*while (shell->cmds[i])
		{
			printf("cmds: %s\n", shell->cmds[i]);
			i++;	
		}*/
	}
}