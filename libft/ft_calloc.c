/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:00:36 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/14 16:00:36 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;

	if (((long)nmemb != 0 && (long)size != 0) && ((long)size < 0
			|| (long)nmemb < 0))
		return (0);
	out = malloc(nmemb * size);
	if (!out)
		return (0);
	ft_bzero(out, (nmemb * size));
	return (out);
}
