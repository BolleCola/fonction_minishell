/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:50:39 by tpaquier          #+#    #+#             */
/*   Updated: 2022/03/07 11:50:40 by tpaquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	isp(char **str, int i, int ret)
{
	int	j;

	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{	
			if (str[i][j] == '|')
			{
				if (ret == 1)
					return (j);
				if (ret == 0)
					return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_pipe(char **str, int i)
{
	int	j;
	int	pi;
	int	bi;

	j = 0;
	bi = i;
	pi = isp(str, i, 0);
	while (str[i])
	{
		if (i == pi)
		{
			j += isp(str, i, 1);
			break ;
		}
		else
			j += (ft_strlen(str[i]) + 1);
		i++;
	}
// valeur de stockage pour la struct -> 'bi' pour 
//à partir de qu'elle argument printf 
// et 'i' pour à qu'elle argument stoper et 
//'j' pour qu'elle lettre de l'argument 'i'
// - 1 ("test|" = 4), pour s'arreter quand le pipe est là.
}

void	ft_wbn(char **str, int i)
{
	if (isp(str, i, 0) == 0)
	{
		while (str[i])
		{
			ft_printf("%s", str[i++]);
			if (str[i])
				ft_printf(" ");
		}
		ft_printf("\n");
	}
	else
		ft_pipe(str, i);
}

void	ft_nbn(char **str, int i)
{
	if (isp(str, i, 0) == 0)
	{
		while (str[i])
		{
			ft_printf("%s", str[i++]);
			if (str[i] != NULL)
				ft_printf(" ");
		}
	}
	else
		ft_pipe(str, i);
}

void	ma_fonction(int argc, char **str)
{
	int		i;
	int		j;
	char	*echo;

	i = 1;
	echo = "echo";
	while (str[i])
	{
		if (str[i][0] == echo[0] && str[i][1] == echo[1] && str[i][2]
			== echo[2] && str[i][3] == echo[3] && str[i][4] == echo[4])
			break ;
		i++;
	}
	if (str[i + 1])
	{
		if (str[i + 1][0] == '-' && str[i + 1][1] == 'n')
			ft_nbn(str, i + 2);
		else
			ft_wbn(str, i + 1);
	}
	else
		ft_printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ma_fonction(argc, argv);
	return (0);
}
