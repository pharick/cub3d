/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:10:27 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/28 13:17:53 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.05

# include <math.h>
# include "structs.h"

void	move_player(t_keys keys, t_config *config);

#endif
