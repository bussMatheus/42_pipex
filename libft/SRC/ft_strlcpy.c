/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:13:25 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/20 20:51:01 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (!size)
		return (i);
	while (*src && --size)
	{
		if (*src == '\'')
			src++;
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	return (i);
}
//Returns the total size of the src and copies the values from src to dst
//having in consideration the size's size, after it, the function ends the dst
//string with the null-terminator.
