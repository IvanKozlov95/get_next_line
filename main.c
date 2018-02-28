/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:37:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/27 23:09:26 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char *av[])
{
	char	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	printf("Testing stdin...\n");
	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
	printf("Result is %s\n", ft_strequ(line, "aaa") ? "OK" : "BAD");
	printf("Return value is %s\n", gnl_ret == 0 || gnl_ret == 1 ? "OK" : "BAD");
	printf("DONE.\n");

	int		fd2;
	int		fd3;
	int		diff_file_size;

	printf("Testing veeeery large file...\n");
	system("mkdir -p tests");
	system("openssl rand -out tests/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");
	fd = open("tests/large_file.txt", O_RDONLY);
	fd2 = open("tests/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, "\n", 1);
	}
	close(fd);
	close(fd2);
	system("diff tests/large_file.txt tests/large_file.txt.mine > tests/large_file.diff");
	fd3 = open("tests/large_file.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);
	printf("DONE. Diff between files is: %d\n", diff_file_size);
	
	printf("Going through arguments...\n");
	int		i;

	i = 0;
	if (ac >= 2)
	{
		while (++i < ac)
		{
			printf("Reading from %s...\n", av[i]);
			fd = open(av[i], O_RDONLY);
			char	*line;
			while (get_next_line(fd, &line) > 0)
				printf("Found line |%s|\n", line); 
			printf("Done\n");
			close(fd);
		}
	}
	printf("DONE.\n");
	return (0);
}
