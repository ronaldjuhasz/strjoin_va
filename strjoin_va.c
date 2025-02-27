/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_va.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuhasz <rjuhasz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:30:59 by rjuhasz           #+#    #+#             */
/*   Updated: 2025/02/27 12:01:41 by rjuhasz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
		len += strlen(str);
	}
	va_end(args);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	*joined = 0;
	va_start(args, count);
	while (i++ < count)
		strcat(joined, va_arg(args, char *));
	return (va_end(args), joined);
}
