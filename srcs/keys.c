/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:21:27 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 11:19:19 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->right = 0;
	keys->left = 0;
}

int		handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keys.w = 1;
	else if (keycode == 1)
		vars->keys.s = 1;
	else if (keycode == 124)
		vars->keys.right = 1;
	else if (keycode == 123)
		vars->keys.left = 1;
	else if (keycode == 2)
		vars->keys.d = 1;
	else if (keycode == 0)
		vars->keys.a = 1;
	else if (keycode == 53)
		handle_exit(vars);
	return (0);
}

int		handle_keyrelease(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keys.w = 0;
	else if (keycode == 1)
		vars->keys.s = 0;
	else if (keycode == 124)
		vars->keys.right = 0;
	else if (keycode == 123)
		vars->keys.left = 0;
	else if (keycode == 2)
		vars->keys.d = 0;
	else if (keycode == 0)
		vars->keys.a = 0;
	return (0);
}
