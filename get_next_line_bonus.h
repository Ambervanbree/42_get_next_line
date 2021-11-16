/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:00:12 by avan-bre          #+#    #+#             */
/*   Updated: 2021/07/13 16:29:48 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H 

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 64
# endif

char	*get_next_line(int fd);
void	free_function(char **string);
int		index_rest(char *string);
char	*join_string(char *line, char *join, size_t size);
char	*substring(char *string, size_t start);
void	split_line(char **line, char **rest, char *buffer, int index);
void	read_file(int fd, char **line, char **rest);

#endif