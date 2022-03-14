/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <armansuy@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:41:44 by armansuy          #+#    #+#             */
/*   Updated: 2022/03/14 15:42:15 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_stpcpy(char *dst, char const *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

char	*my_strchr(char *s, char c)
{
	while (*s != c)
		if (*s++ == '\0')
			return (NULL);
	*s++ = '\0';
	return (s);
}

char	*my_strjoin(char *dst, char const *src)
{
	char	*ret;
	char	*tmp;

	ret = malloc(sizeof(*ret) * (1 + ft_strlen(dst) + ft_strlen(src)));
	tmp = ret;
	if (ret)
	{
		ft_stpcpy(ft_stpcpy(tmp, dst), src);
		free(dst);
		dst = NULL;
	}
	return (ret);
}

char	*my_strdup(char *s)
{
	char	*tmp;
	char	*ret;

	ret = malloc(sizeof(*ret) * (2 + ft_strlen(s)));
	tmp = ret;
	if (ret)
	{
		tmp = ft_stpcpy(tmp, s);
		*tmp++ = '\n';
		*tmp = '\0';
		free(s);
		s = NULL;
	}
	return (ret);
}
