/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:27:44 by chanhhon          #+#    #+#             */
/*   Updated: 2024/07/05 22:00:49 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "csfunc.h"

void	unix_error(char *msg)
{
	extern int	errno;

	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
}

int	shell_read(int fd, void *buf, int count)
{
	int	rc;

	rc = read(fd, buf, count);
	if (rc < 0)
		unix_error("read error");
	return (rc);
}

int	shell_write(int fd, const void *buf, int count)
{
	int	rc;

	rc = write(fd, buf, count);
	if (rc < 0)
		unix_error("write error");
	return (rc);
}

void	*shell_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		unix_error("malloc error");
	return (p);
}
