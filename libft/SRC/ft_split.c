/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:47:23 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/20 21:05:21 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*It count the words in 's', delimited by the character 'c'*/
static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

/*Return 1 (true) if the function made the allocation safely,
otherwise it frees the arrays pointed by 'array' and itself*/
static int	ft_safe_allocate(char **array, int index, size_t len)
{
	array[index] = malloc(sizeof (char) * len);
	if (!array[index])
	{
		while (index > 0)
			free(array[--index]);
		free(array);
		return (0);
	}
	return (1);
}

/*This function returns 1 if it successfully fills the arrays by
copying the delimited words to each position of the array of pointers
with the ft_strlcpy function, otherwise it returns 0*/
static int	ft_filling_arr(char **array, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (!ft_safe_allocate(array, i, len + 1))
				return (0);
			ft_strlcpy(array[i], s - len, len + 1);
			i++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array = malloc(sizeof (char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = NULL;
	if (!ft_filling_arr(array, s, c))
		return (NULL);
	return (array);
}
