/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:35:03 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/15 20:31:42 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <stdlib.h>
# include "../libs/libft/incs/libft.h"

typedef struct	s_shell
{
	char	*cmdline;
	char	**tokens;
	int		n_pipes;
	char	*cmds;
	char	*prompt;
}	t_shell;

void	tokenizing(t_shell *shell);

//parsing
void	parsing(t_shell *shell);

//prompt
char	*init_prompt(void);
#endif