/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:57:01 by avan-bre          #+#    #+#             */
/*   Updated: 2021/07/13 16:00:52 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_string(char *line, char *join, size_t size)
{
	size_t	count;
	size_t	index;
	char	*new_line;

	count = 0;
	if (line != NULL)
		while (line[count] != '\0')
			count++;
	new_line = malloc((count + size + 1) * sizeof(char));
	if (!(new_line))
		return (NULL);
	index = 0;
	while (index < count)
	{
		new_line[index] = line[index];
		index++;
	}
	index = 0;
	while (index < size)
	{
		new_line[count + index] = join[index];
		index++;
	}
	new_line[count + index] = '\0';
	return (new_line);
}

char	*substring(char *string, size_t start)
{
	char	*substring;
	size_t	size;
	size_t	index;

	size = 0;
	while (string[size + start] != '\0')
		size++;
	substring = malloc((size + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	index = 0;
	while (string[start] != '\0' && index < size)
	{
		substring[index] = string[start];
		index++;
		start++;
	}
	substring[index] = '\0';
	return (substring);
}

void	split_line(char **line, char **rest, char *string, int index)
{
	char	*temp;

	temp = *line;
	*line = join_string(*line, string, index);
	free_function(&temp);
	temp = *rest;
	*rest = substring(string, index);
	free_function(&temp);
}

void	read_file(int fd, char **line, char **rest)
{
	int		index;
	int		nr_char_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	nr_char_read = 1;
	while (nr_char_read > 0)
	{
		nr_char_read = read(fd, buffer, BUFFER_SIZE);
		if (nr_char_read == -1)
			return ;
		buffer[nr_char_read] = '\0';
		index = index_rest(buffer);
		if (index >= 0 || nr_char_read == 0)
			break ;
		temp = *line;
		*line = join_string(*line, buffer, nr_char_read);
		free_function(&temp);
	}
	if (nr_char_read != 0)
		split_line(line, rest, buffer, index);
	if (nr_char_read == 0 && *rest != NULL)
		free_function(rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[OPEN_MAX];

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (line);
	if (rest[fd])
	{
		if (index_rest(rest[fd]) > 0)
		{
			split_line(&line, &rest[fd], rest[fd], index_rest(rest[fd]));
			return (line);
		}
		else
		{
			line = substring(rest[fd], 0);
			free_function(&rest[fd]);
		}
	}
	read_file(fd, &line, &rest[fd]);
	return (line);
}
