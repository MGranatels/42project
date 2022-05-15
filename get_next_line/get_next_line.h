/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:10:48 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/15 15:32:35 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

//# define malloc(x) NULL
# define BUFFER_SIZE 2

char	*get_next_line(int fd);
char	*ft_get_line(char *line, char *buff);

void	ft_clean_buff(char *buff);

int		check_line_end(char *buffer);
size_t	ft_strlen(const char *s);

#endif