/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:27:53 by avan-bre          #+#    #+#             */
/*   Updated: 2021/07/13 16:33:28 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
void	free_function(char **string);
int		index_rest(char *string);
char	*join_string(char *line, char *join, size_t size);
char	*substring(char *string, size_t start);
void	split_line(char **line, char **rest, char *buffer, int index);
void	read_file(int fd, char **line, char **rest);

#endif