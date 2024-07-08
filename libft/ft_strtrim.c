/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:20:29 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/14 19:52:37 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set);
static size_t	ft_check_bgn(char const *s1, char const *set);
static size_t	ft_check_end(char const *s1, char const *set);
static size_t	ft_is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;

	if ((ft_check_bgn(s1, set) + ft_check_end(s1, set)) >= ft_strlen(s1))
		return (ft_strdup(""));
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) - ft_check_bgn(s1, set)
				- ft_check_end(s1, set) + 1));
	if (s2 == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(s1) - ft_check_bgn(s1, set)
		- ft_check_end(s1, set))
	{
		s2[i] = s1[i + ft_check_bgn(s1, set)];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static size_t	ft_check_bgn(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) && ft_is_set(s1[i], set) == 1)
		i++;
	return (i);
}

static size_t	ft_check_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0 && ft_is_set(s1[i - 1], set) == 1)
		i--;
	return (ft_strlen(s1) - i);
}

static size_t	ft_is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
