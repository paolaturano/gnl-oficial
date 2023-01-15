/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pturano <pturano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:31:59 by pturano           #+#    #+#             */
/*   Updated: 2023/01/15 00:44:49 by pturano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p_join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = malloc(sizeof(char) * 1);
	if (!s1 || !s2)
		return (NULL);
	p_join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p_join)
		return (NULL);
	while (s1[i])
	{
		p_join[i] = s1[i];
		i++;
	}
	while (s2[j])
		p_join[i++] = s2[j++];
	p_join[i] = '\0';
	free(s1);
	return (p_join);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}
