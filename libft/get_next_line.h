/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:08:37 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 00:28:40 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_list
{
	int					fd;
	char				*content;
	ssize_t				buf_size;
	ssize_t				len;
	int					index;
	struct s_gnl_list	*next;
}				t_gnl_list;

t_gnl_list	*gnl_node_search(int fd, t_gnl_list **start);
t_gnl_list	*gnl_node_create(int fd, t_gnl_list **start, t_gnl_list *tmp);
char		*get_next_line(int fd);
char		*gnl_free(t_gnl_list **node, char **buf, t_gnl_list **start,
				int fd);
int			gnl_readline(int fd, t_gnl_list *node, t_gnl_list **start);
int			gnl_backup(t_gnl_list *node);
int			gnl_strjoin(t_gnl_list *node, char *buf, ssize_t read_size);
int			gnl_strchr(t_gnl_list *node, int c);
int			gnl_strlcpy(char *dst, char *src, ssize_t count);
void		gnl_list_link(t_gnl_list **node, t_gnl_list **start, int fd);

#endif
