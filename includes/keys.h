/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:10:27 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/28 13:47:39 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "structs.h"
# include "clean.h"

void	init_keys(t_keys *keys);
int		handle_keypress(int keycode, t_vars *vars);
int		handle_keyrelease(int keycode, t_vars *vars);

#endif
