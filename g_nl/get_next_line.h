/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:38:13 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/18 05:28:40 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_callocget(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoinget(char *s1, char *s2);
size_t	ft_strlenget(char *str);
ssize_t	ft_strchrget(char *s, int c);
char	*ft_substrget(char *s, unsigned int start, size_t len);
char	*cleaner(char *dirtline);
void	ft_bzeroget(void *s, size_t n);
char	*linereader(int fd, int *readcounter, char *buffereader);

#endif