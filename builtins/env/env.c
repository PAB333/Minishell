/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:05:22 by pibreiss          #+#    #+#             */
/*   Updated: 2025/06/23 23:22:06 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->value)
		{
			ft_putstr(env->name);
			write(1, "=", 1);
			ft_putstr(env->value);
			write(1, "\n", 1);
		}
		env = env->next;
	}
}
