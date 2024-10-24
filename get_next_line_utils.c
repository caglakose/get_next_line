/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakose <cakose@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:52:45 by cakose            #+#    #+#             */
/*   Updated: 2024/10/03 14:53:06 by cakose           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		space_s1;
	int		space_s2;
	char	*tmp_s3;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	space_s1 = ft_strlen(s1);
	space_s2 = ft_strlen(s2);
	tmp_s3 = (char *)malloc(space_s1 + space_s2 + 1);
	if (!tmp_s3)
		return (NULL);
	while (i < space_s1 || i < space_s2)
	{
		if (i < space_s1)
			tmp_s3[i] = s1[i];
		if (i < space_s2)
			tmp_s3[i + space_s1] = s2[i];
		i++;
	}
	tmp_s3[space_s1 + space_s2] = '\0';
	return (tmp_s3);
}

void	*ft_calloc(size_t n)
{
	char	*r;
	size_t	i;

	i = -1;
	r = malloc(n);
	if (!r)
		return (NULL);
	while (++i < n)
		r[i] = '\0';
	return (r);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
