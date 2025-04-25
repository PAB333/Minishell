/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibreiss <pibreiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:56:42 by pibreiss          #+#    #+#             */
/*   Updated: 2025/04/25 08:05:12 by pibreiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd(char *path)
{
	int		result_path;
	char	*cwd;

	result_path = chdir(path);
	if (result_path == -1)
		perror("cd");
	if (result_path == 0)
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
		{
			perror("cd");
			free(cwd);
		}
		//A finir quand une structure env sera creer
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	cd(av[1]);
}