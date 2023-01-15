/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pturano <pturano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:32:09 by pturano           #+#    #+#             */
/*   Updated: 2023/01/15 00:35:23 by pturano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *stock)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\0')
	{
		free(stock);
		return (NULL);
	}
	i++;
	line = malloc((ft_strlen(stock) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (stock[i])
		line[j++] = stock[i++];
	line[j] = '\0';
	free(stock);
	return (line);
}

char	*ft_line(char *stock)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (stock[0] == '\0')
		return (NULL);
	while (stock[size] && stock[size] != '\n')
		size++;
	if (stock[size] == '\n')
		size++;
	line = malloc(size + 1 * sizeof(char));
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *stock)
{
	char	*buffer;
	int		b_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buffer[b_read] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (b_read < 0)
	{
		free(stock);
		return (NULL);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
