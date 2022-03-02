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

	j = 0;
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
	ft_printf("%d\n", j);
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
	if (str[i + 1][0] == '-' && str[i + 1][1] == 'n')
		ft_nbn(str, i + 2);
	else
		ft_wbn(str, i + 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ma_fonction(argc, argv);
	return (0);
}
