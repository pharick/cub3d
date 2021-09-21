/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:10:27 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/04 23:37:05 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "structs.h"
# include "dda.h"
# include "texture.h"
# include "keys.h"
# include "move.h"
# include "render_sprites.h"

int		next_frame(t_vars *vars);
void	render(t_vars *vars);

#endif
