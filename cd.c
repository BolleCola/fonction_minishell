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

void	ma_fonction(int argc, char **str, char **env)
{
	char	*path;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == 'c' && str[i][1] == 'd' && str[i][2] == '\0')
			break ;
		i++;
	}
	i++;
	chdir(str[i]);
	path = ft_strdup("");
	ft_printf("%s\n", getcwd(path, 100));
	free(path);
}

int	main(int argc, char **argv, char **env)
{
	ma_fonction(argc, argv, env);
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
