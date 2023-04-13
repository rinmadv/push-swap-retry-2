/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:43:35 by madavid           #+#    #+#             */
/*   Updated: 2023/02/28 19:44:29 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cut_and_save(char **to_truncate, char *to_save, int buffer_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void) buffer_size;
	while ((*to_truncate)[i] != '\n' && (*to_truncate)[i] != '\0')
		i++;
	i++;
	while (j < buffer_size)
	{
		(to_save)[j] = 0;
		j++;
	}
	j = 0;
	while ((*to_truncate)[i] != '\0')
	{
		(to_save)[j] = (*to_truncate)[i];
		(*to_truncate)[i] = 0;
		i++;
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*stash;
	int			readc;

	stash = "";
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (buffer[0] == '\0')
		readc = read(fd, buffer, BUFFER_SIZE);
	while (find_new_line(buffer) == 0)
	{
		stash = ft_strjoin(stash, buffer);
		readc = read(fd, buffer, BUFFER_SIZE);
		if (readc == -1)
			return (free (stash), NULL);
		buffer[readc] = 0;
		if (readc <= 0)
		{
			if (*stash)
				return (stash);
			return (free(stash), NULL);
		}
	}
	stash = ft_strjoin(stash, buffer);
	return (cut_and_save(&stash, buffer, BUFFER_SIZE), stash);
}
