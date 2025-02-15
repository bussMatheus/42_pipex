/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:41:33 by mely-pan          #+#    #+#             */
/*   Updated: 2024/04/23 20:24:02 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		total_size;
	size_t		dst_size;
	const char	*s;

	s = src;
	dst_size = 0;
	if ((!dst && !src) && size == 0)
		return (0);
	while (dst[dst_size] && dst_size < size)
		dst_size++;
	if (dst_size < size)
		total_size = dst_size + ft_strlen(s);
	else
		return (size + ft_strlen(s));
	while (*s && dst_size + 1 < size)
		dst[dst_size++] = *s++;
	dst[dst_size] = '\0';
	return (total_size);
}
