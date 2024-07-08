/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:51:29 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/19 21:04:11 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_list_link(t_gnl_list **node, t_gnl_list **start, int fd)
{
	t_gnl_list	*tmp;

	tmp = *start;
	while (tmp && tmp->next)
	{
		if (tmp->next->fd == fd)
			tmp->next = (*node)->next;
		tmp = tmp->next;
	}
}

char	*gnl_free(t_gnl_list **node, char **buf, t_gnl_list **start, int fd)
{
	if (node)
	{
		if (*node)
		{
			if (*node == *start)
				*start = (*start)->next;
			else
				gnl_list_link(node, start, fd);
			if ((*node)->content)
				free((*node)->content);
			(*node)->content = 0;
			free(*node);
			*node = 0;
		}
	}
	if (buf)
	{
		if (*buf)
		{
			free(*buf);
			*buf = 0;
		}
	}
	return (0);
}

int	gnl_strjoin(t_gnl_list *node, char *buf, ssize_t read_size)
{
	char	*line;
	ssize_t	i;

	line = 0;
	if (node->buf_size <= node->len + read_size)
	{
		line = (char *)malloc(sizeof(char) * node->buf_size * 2);
		if (line == 0)
			return (-1);
		gnl_strlcpy(line, node->content, node->len);
		free(node->content);
		node->content = line;
		node->buf_size = node->buf_size * 2;
	}
	i = -1;
	while (++i < read_size)
		node->content[node->len + i] = buf[i];
	node->content[node->len + i] = 0;
	i = 0;
	node->len = 0;
	while (node->content[i++])
		node->len += 1;
	return (1);
}

int	gnl_strchr(t_gnl_list *node, int c)
{
	int	i;

	i = -1;
	while (node->content[++i])
	{
		if (node->content[i] == (char)c)
		{
			node->index = i + 1;
			return (-1);
		}
	}
	node->index = i;
	return (-2);
}

int	gnl_strlcpy(char *dst, char *src, ssize_t count)
{
	ssize_t	i;

	i = 0;
	while (i < count && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (1);
}
