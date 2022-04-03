/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:21:28 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/11 16:45:09 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

#define BUFFER_SIZE 2

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_get_line(char *line, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	temp = line;
	i = 0;
	line = malloc(sizeof(char) * ft_strlen(line) + ft_strlen(buff));
	if (!line)
		return (0);
	while (temp && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		line[i] = buff[j];
		if (buff[j++] == '\n')
			break ;
		i++;
	}
	line [i] = '\0';
	return (line);
}

void	ft_clean_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buff[i] && buff[i] != '\n')
	{
		if (j == 0 && buff[i] == '\n')
			j = 0;
		else if (j >= 0)
			buff[j++] = buff[i];
		buff[i++] = 0;
	}
}

int	check_line_end(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	return (buff[i] != '\n');
}

char	*ft_get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	int			i;
	int			re;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	i = 1;
	line = NULL;
	while (i)
	{
		re = 1;
		if (buff[0])
			re = read(fd, buff, BUFFER_SIZE);
		i = check_line_end(buff);
		if (re > 0)
			line = ft_get_line(line, buff);
		ft_clean_buff(buff);
	}
	return (line);
}
