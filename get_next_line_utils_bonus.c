/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:23:51 by sben-chi          #+#    #+#             */
/*   Updated: 2022/02/11 09:52:11 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cat_copy(char *s1, char *s2, int len)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !*s2)
		return (NULL);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	while (s1 && (s1)[j])
		t[i++] = s1[j++];
	if (s1)
		free (s1);
	j = 0;
	while (i <= (len - 1))
		t[i++] = s2[j++];
	t[i] = '\0';
	i = 0;
	while (s2[j])
		(s2)[i++] = (s2)[j++];
	(s2)[i] = '\0';
	return (t);
}
