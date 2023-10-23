/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:38:03 by aapostol          #+#    #+#             */
/*   Updated: 2022/11/01 19:16:25 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*new;
	void	*tmp;

	copy = NULL;
	while (lst)
	{
		tmp = (*f)(lst->content);
		if (!tmp)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		new = ft_lstnew(tmp);
		if (!new)
		{
			free(tmp);
			ft_lstclear(&copy, del);
			return (NULL);
		}
		ft_lstadd_back(&copy, new);
		lst = lst->next;
	}
	return (copy);
}
