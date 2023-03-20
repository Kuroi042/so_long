/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:37:08 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/01 19:00:41 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			readcounter;
	char		*buffereader;
	static char	*frag;

	buffereader = ft_callocget(BUFFER_SIZE + 2, 1);
	readcounter = 1;
	if (frag)
	{
		buffereader = ft_strjoinget(buffereader, frag);
		free(frag);
		frag = NULL;
	}
	buffereader = linereader(fd, &readcounter, buffereader);
	if (buffereader && ft_strchrget(buffereader, '\n') != -1)
	{
		frag = ft_substrget(buffereader, ft_strchrget(buffereader, '\n') + 1,
				ft_strchrget(buffereader, '\0'));
		buffereader = cleaner(buffereader);
	}
	if (readcounter == 0 && ft_strlenget(buffereader) == 0)
	{
		free(buffereader);
		return (NULL);
	}
	return (buffereader);
}

void	ft_bzeroget(void *s, size_t n)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *)s;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}

char	*linereader(int fd, int *readcounter, char *buffereader)
{
	char	*buffer;

	buffer = ft_callocget(BUFFER_SIZE + 1, 1);
	while ((ft_strchrget(buffer, '\n') == -1) && (*readcounter > 0))
	{
		ft_bzeroget(buffer, BUFFER_SIZE);
		*readcounter = read(fd, buffer, BUFFER_SIZE);
		if (*readcounter == -1)
		{
			free(buffereader);
			free(buffer);
			return (NULL);
		}
		buffereader = ft_strjoinget(buffereader, buffer);
	}
	free(buffer);
	return (buffereader);
}

char	*cleaner(char *dirtline)
{
	char	*cleanline;

	cleanline = ft_substrget(dirtline, 0, ft_strchrget(dirtline, '\n') + 1);
	free(dirtline);
	return (cleanline);
}
