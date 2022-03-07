/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:50:28 by tpaquier          #+#    #+#             */
/*   Updated: 2022/03/07 11:50:30 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int argc, char **argv, char **envp)
{
	char	*test;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		test = envp[i];
		if (envp[i + 1])
			ft_printf("%s\n", test);
		else
			ft_printf("_=/usr/bin/env\n");
		i++;
	}
}
