/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:37:32 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/22 20:09:54 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;

	if (!s)
		return (NULL);
	new_s = (char *)malloc(sizeof (char) * ft_strlen(s) + 1);
	if (!new_s)
		return (NULL);
	ft_strcpy(new_s, s);
	return (new_s);
}
