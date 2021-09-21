/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:46:37 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 14:10:11 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "parse_map.h"
# include "texture.h"
# include "errors.h"
# include "clean.h"

int	config_load(t_vars *vars, char *path);

#endif
