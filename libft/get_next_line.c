/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:51:26 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 00:27:15 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_backup(t_gnl_list *node)
{
	int	i;

	i = 0;
	if (node->index - 1 != node->len)
	{
		while (node->content[node->index + i])
		{
			node->content[i] = node->content[node->index + i];
			i++;
		}
	}
	node->len = i;
	node->content[i] = 0;
	return (i);
}

int	gnl_readline(int fd, t_gnl_list *node, t_gnl_list **start)
{
	ssize_t		read_size;
	char		*buf;
	int			check;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0 || node == 0)
		return ((int)gnl_free(&node, 0, start, fd));
	read_size = read (fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		check = gnl_strjoin(node, buf, read_size);
		if (check < 0)
			return ((int)gnl_free(&node, &buf, start, fd));
		check = gnl_strchr(node, (int) '\n');
		if (check == -1)
			break ;
		read_size = read (fd, buf, BUFFER_SIZE);
	}
	if (read_size < 0)
		return ((int)gnl_free(&node, &buf, start, fd));
	if (read_size == 0)
		gnl_strchr(node, (int) '\n');
	free(buf);
	return (1);
}

t_gnl_list	*gnl_node_create(int fd, t_gnl_list **start, t_gnl_list *tmp)
{
	t_gnl_list	*new;
	int			i;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (new == 0)
		return (0);
	if (*start != 0)
		tmp->next = new;
	else
		*start = new;
	new->fd = fd;
	new->next = 0;
	new->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new->content == 0)
		return ((t_gnl_list *)gnl_free(&new, 0, start, fd));
	i = -1;
	while (++i < BUFFER_SIZE + 1)
		new->content[i] = 0;
	new->len = 0;
	new->buf_size = BUFFER_SIZE + 1;
	new->index = 0;
	return (new);
}

t_gnl_list	*gnl_node_search(int fd, t_gnl_list **start)
{
	t_gnl_list	*tmp;
	t_gnl_list	*new;

	tmp = *start;
	while (tmp != 0)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next == 0)
			break ;
		tmp = tmp->next;
	}
	new = gnl_node_create(fd, start, tmp);
	if (new == 0)
		return (0);
	return (new);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*start;
	t_gnl_list			*node;
	char				*line;
	int					check;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	node = gnl_node_search(fd, &start);
	if (node == 0)
		return (0);
	check = gnl_readline(fd, node, &start);
	if (check == 0)
		return (0);
	line = (char *)malloc(sizeof(char) * (node->index + 1));
	if (line == 0)
		return (gnl_free(&node, 0, &start, fd));
	gnl_strlcpy(line, node->content, node->index);
	if (node->index == 0 && node->len == 0)
		return (gnl_free(&node, &line, &start, fd));
	check = gnl_backup(node);
	if (check == 0)
		gnl_free(&node, 0, &start, fd);
	return (line);
}
