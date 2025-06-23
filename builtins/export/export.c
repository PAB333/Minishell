/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:57:04 by pibreiss          #+#    #+#             */
/*   Updated: 2025/06/24 00:30:35 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_split(char **split_arg)
{
	int	i;

	i = 0;
	while (split_arg[i])
	{
		free(split_arg[i]);
		i++;
	}
	free(split_arg);
}

void	add_env(t_env **env, char **arg)
{
	t_env	*new;
	t_env	*tmp;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->name = ft_strdup(arg[0]);
	if (arg[1])
		new->value = ft_strdup(arg[1]);
	else if (!arg[1])
		new->value = NULL;
	new->next = NULL;
	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	tmp = *env;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	free_split(arg);
}

void	update_env(t_env **env, char **arg)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, arg[0]) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(arg[1]);
			break ;
		}
		tmp = tmp->next;
	}
	free_split(arg);
}

void	ft_export(t_cmd *cmd, t_env **env)
{
	int		i;
	char	**split_arg;
	t_env	*tmp;

	i = 0;
	if (cmd->args[1] == NULL)
		ft_env_export(*env);
	else
	{
		while (cmd->args[++i])
		{
			split_arg = ft_split(cmd->args[i], '=');
			tmp = *env;
			while (tmp->next != NULL)
			{
				if (ft_strcmp(tmp->name, split_arg[0]) == 0)
					break ;
				tmp = tmp->next;
			}
			if (tmp->next == NULL && ft_strcmp(tmp->name, split_arg[0]) != 0)
				add_env(env, split_arg);
			else if (split_arg[1])
				update_env(env, split_arg);
		}
	}
}
