/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:33:42 by mely-pan          #+#    #+#             */
/*   Updated: 2024/05/13 19:51:18 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*s_ptr;

	s_ptr = s;
	while (n--)
		*(unsigned char *)s++ = (unsigned char)c;
	return (s_ptr);
}
//Memory Filling Loop:

//str_ptr = str; Assigns the pointer str to str_ptr. This saves
//the original starting address of the memory block to be returned later.
//while (n--): This loop runs n times, decrementing n with each
//iteration until it reaches 0.
//*(unsigned char *)str++ = (unsigned char)c;:
//(unsigned char *)str++: Casts str to an unsigned char * pointer
//to allow byte-wise access.
//*(unsigned char *)str++ = (unsigned char)c;: Sets the byte
//pointed to by str to the value of c (converted to unsigned char
//to ensure it fits within a byte).
//str++: Moves the str pointer to the next byte
//(due to pointer arithmetic). This is why we saved
//str initially (str_ptr = str;) so that we can return
//the original pointer.
