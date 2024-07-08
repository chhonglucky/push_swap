/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:00:28 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 00:29:00 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while ((*p1) && (*p1 == *p2))
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}
