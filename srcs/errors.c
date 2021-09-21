/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:37:03 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 13:47:51 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	print_error(int error_code)
{
	if (error_code == ERROR_ARGS)
		ft_putendl_fd("Usage: ./cub3d config_path [--save]", 2);
	else if (error_code == ERROR_MLX_INIT)
		ft_putendl_fd("Error\nMlx init error", 2);
	else if (error_code == ERROR_WINDOW)
		ft_putendl_fd("Error\nWindow init error", 2);
	else if (error_code == ERROR_IMG)
		ft_putendl_fd("Error\nImage init error", 2);
	else if (error_code == ERROR_MALLOC)
		ft_putendl_fd("Error\nMemory allocation error", 2);
	else if (error_code == ERROR_CONFIG)
		ft_putendl_fd("Error\nWrong config", 2);
	return (error_code);
}
