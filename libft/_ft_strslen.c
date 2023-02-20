/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:16:25 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:30:20 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (-1);
	while (strs[i] != 0)
		i++;
	return (i);
}
