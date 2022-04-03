/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:02:22 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/22 16:24:24 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE];
	char		*line;
	size_t		i;
	size_t		re;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	line = NULL;
	i = 1;
	while (i)
	{
		re = 1;
		if (!buff[fd][0])
			re = read(fd, buff[fd], BUFFER_SIZE);
		i = (check_line_end(buff[fd]) && (re > 0));
		if (re > 0)
			line = ft_get_line(line, buff[fd]);
		ft_clean_buff(buff[fd]);
	}
	return (line);
}
