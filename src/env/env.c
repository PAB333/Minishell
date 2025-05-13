/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:05:22 by pibreiss          #+#    #+#             */
/*   Updated: 2025/05/12 17:48:48 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr(envp[i]);
		write(1, "\n", 1);
		i++;
	}
}

// int	main(int ac, char **av, char **envp)
// {
// 	env(envp);
// }