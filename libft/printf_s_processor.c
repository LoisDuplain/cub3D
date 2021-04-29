/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s_processor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:47:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/03/19 16:46:21 by lduplain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	s_processor(	\
	t_printable *prtbl,	\
	va_list args,		\
	char **to_print)
{
	char	*value;
	int		to_dup;

	value = va_arg(args, char *);
	if (value == NULL)
		*to_print = ft_strdup("(null)", FALSE);
	else
		*to_print = ft_strdup(value, FALSE);
	if (prtbl->dot)
	{
		to_dup = ft_min(prtbl->dot_value, ft_strlen(*to_print));
		*to_print = ft_strndup(*to_print, to_dup, TRUE);
	}
}
