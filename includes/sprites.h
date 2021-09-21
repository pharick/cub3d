/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 12:33:52 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/06 16:23:34 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include <stdlib.h>
# include "structs.h"

void	parse_sprites(t_config *config);
void	sort_sprites(t_config config);

#endif
