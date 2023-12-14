/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_util.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:46:21 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:12:24 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_addc_free_s(char *s, char c)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = malloc(i + 2);
	if (str == NULL)
		err_free_exit(s, NULL, "malloc failed!\n");
	ft_strlcpy(str, s, i + 1);
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*ft_addtext_free_s(char *s, char *text)
{
	char	*str;

	str = ft_strjoin(s, text);
	if (str == NULL)
		err_free_exit(s, NULL, "malloc failed\n");
	free(s);
	return (str);
}

char	*ft_s_ini(char *ss)
{
	char	*s;

	s = malloc(sizeof(char) * 1);
	if (s == NULL)
	{
		if (ss != NULL)
			free(ss);
		err_message_exit("malloc failed!\n");
	}	
	s[0] = '\0';
	return (s);
}

char	*ft_newstr(char *org, char *str, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		err_free_exit(org, NULL, "malloc for get mapdata failed\n");
	new[size] = '\0';
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char	*ft_readdata(char *file, char *s)
{
	int		fd;
	int		r;
	int		i;
	char	text[BUFFER_SIZE + 1];

	fd = 1;
	r = 1;
	i = 0;
	text[BUFFER_SIZE] = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_free_exit(s, NULL, "can not open the file.\n");
	while (r > 0)
	{
		r = read(fd, &text, BUFFER_SIZE);
		if (r < 0)
			err_free_exit(s, NULL, "read failed.\n");
		if (r > 0)
		{
			text[r] = '\0';
			s = ft_addtext_free_s(s, text);
		}			
	}
	close (fd);
	return (s);
}
