/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <armansuy@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:30:48 by armansuy          #+#    #+#             */
/*   Updated: 2022/03/14 15:31:20 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*newstr(void);
static char	*freestr(char *s);
static void	ft_bzero(void *b, size_t n);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*found;
	size_t		bytes;

	bytes = BUFFER_SIZE;
	line = newstr();
	while (BUFFER_SIZE > 0 && line && !read(fd, buf, 0))
	{
		found = my_strchr(buf, '\n');
		line = my_strjoin(line, buf);
		if (found)
		{
			ft_stpcpy(buf, found);
			return (my_strdup(line));
		}
		ft_bzero(buf, BUFFER_SIZE);
		if (bytes != BUFFER_SIZE)
			return (line);
		bytes = read(fd, buf, BUFFER_SIZE);
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
