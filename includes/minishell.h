/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:58:33 by pibreiss          #+#    #+#             */
/*   Updated: 2025/06/25 01:37:45 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char			**args;
	char			*input_file;
	char			*output_file;
	int				append;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *source);
int		ft_atoi(char *str);
void	ft_env(t_env *envp);
void	ft_env_export(t_env *envp);
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
int		count_arg(char **arg);

#endif