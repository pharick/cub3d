/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:39:54 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 13:33:42 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"

int	handle_exit(t_vars *vars)
{
	clean_exit(vars, 0);
	return (0);
}

int	clean_exit(t_vars *vars, int code)
{
	if (vars->mlx && vars->window)
		mlx_destroy_window(vars->mlx, vars->window);
	if (vars->mlx && vars->frame.img)
		mlx_destroy_image(vars->mlx, vars->frame.img);
	if (vars->mlx && vars->buffer.img)
		mlx_destroy_image(vars->mlx, vars->buffer.img);
	if (vars->config.map)
		ft_free_tokens(vars->config.map, vars->config.map_height);
	if (vars->mlx && vars->config.textures.north.img)
		mlx_destroy_image(vars->mlx, vars->config.textures.north.img);
	if (vars->mlx && vars->config.textures.south.img)
		mlx_destroy_image(vars->mlx, vars->config.textures.south.img);
	if (vars->mlx && vars->config.textures.east.img)
		mlx_destroy_image(vars->mlx, vars->config.textures.east.img);
	if (vars->mlx && vars->config.textures.west.img)
		mlx_destroy_image(vars->mlx, vars->config.textures.west.img);
	if (vars->mlx && vars->config.textures.sprite.img)
		mlx_destroy_image(vars->mlx, vars->config.textures.sprite.img);
	if (vars->z_buffer)
		free(vars->z_buffer);
	if (vars->config.sprites)
		free(vars->config.sprites);
	if (vars->config.sprites_order)
		free(vars->config.sprites_order);
	exit(code);
}
