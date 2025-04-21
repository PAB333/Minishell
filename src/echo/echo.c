/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:03:48 by pibreiss          #+#    #+#             */
/*   Updated: 2025/04/21 18:07:08 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	echo(char **tab, int option)
{
	int	i;

	i = 0;
	if (!tab)
	{
		write(1, "\n", 1);
		return ;
	}
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (!(tab[i + 1] == NULL))
			write(1, " ", 1);
		i++;
	}
	if (option == 1)
		return ;
	else
		write(1, "\n", 1);
}
