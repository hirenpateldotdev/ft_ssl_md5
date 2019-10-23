/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:47:23 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:47:26 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	begin = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		temp = temp->next;
	}
	return (begin);
}
