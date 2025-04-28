/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:03:48 by pibreiss          #+#    #+#             */
/*   Updated: 2025/04/28 14:36:35 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo(char **tab)
{
	int	i;
	int	option;

	i = 1;
	if (tab[i] && ft_strcmp(tab[i], "-n") == 0)
	{
		i++;
		option = 1;
	}
	if (!tab[i] && option != 1)
	{
		write(1, "\n", 1);
		return ;
	}
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (option != 1)
		write(1, "\n", 1);
}
