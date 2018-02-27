/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:54:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/26 21:53:14 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

# define BUFF_SIZE (10)
# define FT_LIMIT (4864)
# define EOF (-1)

int			get_next_line(const int fd, char **line);
