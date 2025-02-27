/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_va.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuhasz <rjuhasz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:30:59 by rjuhasz           #+#    #+#             */
/*   Updated: 2025/02/27 10:56:12 by rjuhasz          ###   ########.fr       */
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
	i = 0;
	len = 0;
	va_start(args, count);
	while (i < count)
	{
		str = va_arg(args, char *);
		len += strlen(str);
		i++;
	}
	va_end(args);
	joined = malloc(sizeof joined + 1);
	*joined = 0;
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		strcat(joined, va_arg(args, char*));
		i++;
	}
	va_end(args);
	return (joined);
}

int main() {
    char *result = strjoin_va(3, "Hello", " ", "World!");
    if (result) {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}