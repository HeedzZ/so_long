/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:57:09 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/14 15:52:28 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count + 1);
}

static char	*ft_get_word(char *str, char c, int *n)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (str[*n] == c && str[*n])
		*n = *n + 1;
	while (str[*n + len] != c && str[*n + len])
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[*n];
		i++;
		*n = *n + 1;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		nb_word;
	int		j;
	int		i;
	char	**tab;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	nb_word = ft_count_words((char *)s, c);
	tab = malloc(nb_word * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < nb_word - 1)
	{
		tab[i] = ft_get_word((char *)s, c, &j);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/*int	main(int ac, char **av)
{
	int i;
	char **tab;

	tab = ft_split(av[1], av[2]);
	i = 0;
	while (i < 6)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/