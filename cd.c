/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:50:49 by tpaquier          #+#    #+#             */
/*   Updated: 2022/03/07 11:50:50 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_cd(t_shell *shell)
{
	char	*path;
	int		i;

	i = 0;
	while (shell->cmd->args[i])
	{
		if (shell->cmd->args[i][0] == 'c' && shell->cmd->args[i][1] == 'd' &&
			 shell->cmd->args[i][2] == '\0')
			break ;
		i++;
	}
	i++;
	if (chdir(shell->cmd->args[i]) == -1)
	{
		ft_printf("cd: ");
		perror(shell->cmd->args[i]);
	}
	else
		chdir(shell->cmd->args[i]);
	path = ft_strdup("");
	ft_printf("%s\n", getcwd(path, 100));
	free(path);
}

int	main(int argc, char **argv, char **env)
{
	t_shell *shell;
	ma_fonction(shell);
	return (0);
}

/*
path = getenv("PWD");
oldpath = getenv("OLDPWD");
ft_printf("%s\n%s\n", path, oldpath);

ft_printf("%s\n", getcwd(path, 100));

	chdir("..");

	ft_printf("%s\n", getcwd(path, 100));

	chdir("fonction_minishell");

	ft_printf("%s\n", getcwd(path, 100));
*/
