/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:35:20 by cbelva            #+#    #+#             */
/*   Updated: 2021/01/05 15:11:46 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "libft.h"

enum	e_errors
{
	ERROR_MLX_INIT = 1,
	ERROR_CONFIG,
	ERROR_WINDOW,
	ERROR_IMG,
	ERROR_MALLOC,
	ERROR_ARGS
};

int	print_error(int error_code);

#endif
