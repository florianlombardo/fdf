/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 12:30:02 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 12:30:03 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;
	t_list	*prev;

	if (lst)
	{
		if (!(begin = (t_list*)malloc(sizeof(t_list))))
			return (0);
		begin = (*f)(lst);
		lst = lst->next;
		prev = begin;
	}
	while (lst)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (0);
		new = (*f)(lst);
		prev->next = new;
		lst = lst->next;
		prev = new;
	}
	return (begin);
}
