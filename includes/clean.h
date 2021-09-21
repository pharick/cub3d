/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:46:37 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 13:33:36 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "mlx.h"
# include "libft.h"
# include "structs.h"

int	handle_exit(t_vars *vars);
int	clean_exit(t_vars *vars, int code);

#endif
