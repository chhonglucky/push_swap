/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:27:51 by chanhhon          #+#    #+#             */
/*   Updated: 2024/07/08 21:09:26 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSFUNC_H
# define CSFUNC_H

# include <unistd.h>
# include "push_swap.h"

void	unix_error(char *msg);
int		shell_read(int fd, void *buf, int count);
int		shell_write(int fd, const void *buf, int count);
void	*shell_malloc(size_t size);

#endif
