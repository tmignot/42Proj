/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strirchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 02:32:25 by tmignot           #+#    #+#             */
/*   Updated: 2014/04/19 02:32:29 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strirchr(const char *str, int l)
{
	int		i;
	char	c;

	i = 0;
	c = (unsigned char)l;
	while (((char*)str)[i] != '\0')
		i++;
	while (((char*)str)[i] != c)
	{
		if (i < 0)
			return (0);
		i--;
	}
	return (i);
}
