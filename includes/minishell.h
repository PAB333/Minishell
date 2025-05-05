/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:58:33 by pibreiss          #+#    #+#             */
/*   Updated: 2025/05/05 17:49:34 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char			**args; 
	char			*input_file;
	char			*output_file;
	int				append;
	struct s_cmd	*next;
}	t_cmd;

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif