/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:22:24 by sben-chi          #+#    #+#             */
/*   Updated: 2022/02/11 09:51:00 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	free_buff(char ***buff, char **buff2)
{
	int	i;

	i = 0;
	if (!(**buff2))
	{
		free(*buff2);
		*buff2 = NULL;
	}
	if (!*buff[0])
	{
		while (i < OPEN_MAX)
		{
			if ((*buff)[i++])
				break ;
		}
		if (i == OPEN_MAX)
		{
			free(*buff);
			*buff = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	**buff;
	char		*t;
	int			i;

	i = 0;
	if (fd <= -1 || fd >= OPEN_MAX)
		return (NULL);
	if (!buff)
	{
		buff = malloc(sizeof(char *) * OPEN_MAX);
		if (!buff)
			return (NULL);
		while (i < OPEN_MAX)
			buff[i++] = NULL;
	}
	if (!buff[fd])
	{
		buff[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buff[fd][0] = '\0';
	}	
	t = t_return(fd, 0, buff[fd]);
	free_buff(&buff, &buff[fd]);
	return (t);
}
