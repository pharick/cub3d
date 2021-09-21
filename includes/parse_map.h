/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 00:10:27 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 14:09:32 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "libft.h"
# include "structs.h"
# include "sprites.h"

int	parse_map(t_config *config, char *line, int fd);

#endif
