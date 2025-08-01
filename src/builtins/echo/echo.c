/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:03:48 by pibreiss          #+#    #+#             */
/*   Updated: 2025/06/24 22:55:32 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_option(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 2;
	while (arg[i] == 'n')
		i++;
	return (arg[i] == '\0');
}

void	ft_echo(t_cmd *cmd)
{
	int	i;
	int	j;
	int	option;

	i = 1;
	while (cmd->args[i] && is_option(cmd->args[i]))
	{
		option = 1;
		i++;
	}
	if (!cmd->args[i] && option != 1)
	{
		write(1, "\n", 1);
		return ;
	}
	while (cmd->args[i])
	{
		ft_putstr(cmd->args[i]);
		if (cmd->args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (option != 1)
		write(1, "\n", 1);
}
