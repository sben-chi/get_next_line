/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:59:53 by sben-chi          #+#    #+#             */
/*   Updated: 2022/02/07 09:19:42 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*t_return(int fd, int a, char *buff)
{
	char	*t;
	int		t_len;

	t = NULL;
	t_len = 0;
	while (buff[a] != '\n')
	{
		if (buff[a] == '\0')
		{
			t_len += a;
			t = cat_copy(t, buff, t_len);
			a = read(fd, buff, BUFFER_SIZE);
			if (a <= 0)
				return (t);
			buff[a] = '\0';
			a = -1;
		}
		a++;
	}
	t_len += a + 1;
	return (cat_copy(t, buff, t_len));
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*t;

	if (fd <= -1 || fd >= OPEN_MAX)
		return (NULL);
	if (!buff)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	t = t_return(fd, 0, buff);
	if (!*buff)
	{
		free (buff);
		buff = NULL;
	}
	return (t);
}
