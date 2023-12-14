/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_strlist.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:41:29 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:12:24 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_data_strlist(char **src, char c, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\n' && s[i] != '\0')
			i++;
		if (s[i] == c || s[i] == '\n' || s[i] == '\0')
		{
			src[j] = s;
			if (s[i] == '\0')
				break ;
			s[i] = '\0';
			i++;
			j++;
			while (s[i] == c || s[i] == '\n')
				i++;
			s = &s[i];
			i = 0;
		}
	}
	return (src);
}

char	**ft_get_strlist(char *s, char c, int size, t_maps *p)
{
	char	**src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	src = (char **)malloc(sizeof(src) * (size + 1));
	if (!src)
		err_free_exit(s, p, "mallof for string list failed\n");
	src[size] = NULL;
	while (s[0] == c || s[0] == '\n')
		s++;
	src = ft_data_strlist(src, c, s);
	return (src);
}

int	ft_get_alt(char *s)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
		{
			s[i] = '\0';
			a = ft_atoi(s);
			s[i] = ',';
			return (a);
		}
		i++;
	}
	a = ft_atoi(s);
	return (a);
}

void	ft_make_alt( t_maps *p_map)
{
	int	i;

	i = 0;
	p_map->alt = malloc((sizeof p_map->alt) * (p_map->item + 1));
	if (p_map->alt == NULL)
		err_free_exit(NULL, p_map, "malloc for altdata failed\n");
	while (i < p_map->item)
	{
		p_map->alt[i] = ft_get_alt(p_map->data[i]);
		i++;
	}
}
