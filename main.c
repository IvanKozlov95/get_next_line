/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:37:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/27 19:12:19 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char *av[])
{
	int		fd;
	if (ac >= 2)
	{
			fd = open(av[1], O_RDONLY);
			char	*line;
			while (get_next_line(fd, &line) > 0)
				printf("Found line |%s|\n", line); 
			printf("Done\n");
			close(fd);
	}
	return (0);
}