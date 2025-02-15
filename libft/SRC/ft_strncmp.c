/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:11:54 by mely-pan          #+#    #+#             */
/*   Updated: 2024/04/23 21:28:53 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 && !*s2)
			return (1);
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
