/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:04:31 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 00:26:51 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c);
static char		*ft_strdup_modified(char const *src, char c);
static size_t	ft_count_section(char const *s, char c);
static void		ft_freeall(char **str, size_t i);
static char		**ft_assign_data(char **return_array, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**return_array;

	return_array = (char **)malloc((ft_count_section(s, c) + 1)
			* sizeof(char *));
	if (return_array == 0)
		return (0);
	return_array = ft_assign_data(return_array, s, c);
	if (return_array == 0)
		return (0);
	return_array[ft_count_section(s, c)] = 0;
	return (return_array);
}

static size_t	ft_count_section(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strdup_modified(char const *src, char c)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = 0;
	while (size < ft_strlen(src) && src[size] != c)
		size++;
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_freeall(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

static char	**ft_assign_data(char **return_array, char const *s, char c)
{
	char	*check;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < ft_strlen(s))
	{
		if (s[j] != c)
		{
			check = ft_strdup_modified(&s[j], c);
			if (check == 0)
			{
				ft_freeall(return_array, i);
				return (0);
			}
			return_array[i] = check;
			j += ft_strlen(return_array[i]);
			i++;
		}
		else
			j++;
	}
	return (return_array);
}
