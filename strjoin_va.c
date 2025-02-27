/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_va.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuhasz <rjuhasz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:30:59 by rjuhasz           #+#    #+#             */
/*   Updated: 2025/02/27 12:21:09 by rjuhasz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *str, char *add)
{
	int	start;
	int	i;

	if (!str)
		return (NULL);
	if (!add)
		return (str);
	start = 0;
	while (str[start])
		start++;
	i = 0;
	while (add[i])
		str[start++] = add[i++];
	str[start] = 0;
	return (str);
}

char	*strjoin_va(int count, ...)
{
	char	*joined;
	char	*str;
	va_list	args;
	int		i;
	int		len;

	if (count < 1)
		return (NULL);
	i = count--;
	len = 0;
	va_start(args, count);
	while (i--)
	{
		str = va_arg(args, char *);
		len += ft_strlen(str);
	}
	va_end(args);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	*joined = 0;
	va_start(args, count);
	while (i++ < count)
		ft_strcat(joined, va_arg(args, char *));
	return (va_end(args), joined);
}
