/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:02:31 by chanhhon          #+#    #+#             */
/*   Updated: 2023/11/09 22:07:52 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*addlst;
	t_list	*return_lst;
	void	*check;

	return_lst = 0;
	while (lst)
	{
		check = f(lst->content);
		if (check == NULL)
		{
			ft_lstclear(&return_lst, del);
			return (NULL);
		}
		addlst = ft_lstnew(check);
		if (addlst == 0)
		{
			del(check);
			ft_lstclear(&return_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&return_lst, addlst);
		lst = lst->next;
	}
	return (return_lst);
}
