/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:57:06 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/15 15:12:36 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

static size_t	ft_count_words(char const *s)
{
	size_t	i;
	size_t	count;
	char	inside_q;

	i = 0;
	count = 0;
	inside_q = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		count++;
		if (s[i] == '\'' || s[i] == '\"')
			i += iterate_through_q(s, i, &inside_q);
		else if (is_special_char(s[i]))
			i++;
		else
		{
			while (s[i] && s[i] != ' ' && !is_special_char(s[i]))
				i += iterate_through_q(s, i, &inside_q);
		}
	}
	return (count);
}

static int	ft_safe_allocate(char **array, int index, size_t len)
{
	array[index] = malloc(sizeof(char) * (len + 1));
	if (!array[index])
	{
		while (index > 0)
			free(array[--index]);
		free(array);
		return (0);
	}
	return (1);
}

static int	ft_filling_arr(char **array, char const *s)
{
	size_t	l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		l = iteration_cases(s, i);
		if (!ft_safe_allocate(array, j, l))
			return (0);
		ft_strlcpy(array[j], s + i, l + 1);
		j++;
		i += l;
	}
	return (1);
}

char	**ft_split_shell(char const *s)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	printf("words allocated %ld\n", words);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = NULL;
	if (!ft_filling_arr(array, s))
		return (NULL);
	return (array);
}
