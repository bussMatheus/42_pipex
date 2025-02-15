/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:35:48 by mely-pan          #+#    #+#             */
/*   Updated: 2025/02/15 15:12:50 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 10

/*---------------------------------------*/
/*              STRING FUNCTIONS         */

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**ft_split_shell(char const *s);
size_t	iterate_through_q(const char *s, size_t i, char *quote_type);
size_t	iteration_cases(const char *s, size_t i);
int		is_special_char(char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*---------------------------------------*/
/*              WRITE FUNCTIONS          */

void	ft_putstr_fd(char *s, int fd);

/*---------------------------------------*/
/*              MEMORY  FUNCTIONS          */

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*---------------------------------------*/
/*              	GNL						*/
char	*ft_strjoin_gnl(char *s1, char *s2);
int		cut_remaining(char *buf);
char	*get_next_line(int fd);

#endif
