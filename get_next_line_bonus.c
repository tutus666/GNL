/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <armansuy@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:40:49 by armansuy          #+#    #+#             */
/*   Updated: 2022/03/14 15:41:36 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*newstr(void);
static char	*freestr(char *s);
static void	ft_bzero(void *b, size_t n);

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*found;
	size_t		bytes;

	bytes = BUFFER_SIZE;
	line = newstr();
	while (BUFFER_SIZE > 0 && line && !read(fd, buf[fd], 0))
	{
		found = my_strchr(buf[fd], '\n');
		line = my_strjoin(line, buf[fd]);
		if (found)
		{
			ft_stpcpy(buf[fd], found);
			return (my_strdup(line));
		}
		ft_bzero(buf[fd], BUFFER_SIZE);
		if (bytes != BUFFER_SIZE)
			return (line);
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes < 1 && !(*line))
			break ;
	}
	return (freestr(line));
}

static void	ft_bzero(void *b, size_t n)
{
	while (n--)
		*(char *)b++ = 0;
}

static char	*newstr(void)
{
	char	*ret;

	ret = malloc(1);
	*ret = '\0';
	return (ret);
}

static char	*freestr(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}
