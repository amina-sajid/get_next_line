/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:51:19 by asajid            #+#    #+#             */
/*   Updated: 2023/02/16 12:31:21 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*readfile(int fd, char *buf, char *var)
{
	int		len;
	char	*temp;

	len = 1;
	while (len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (0);
		else if (len == 0)
			break ;
		buf[len] = '\0';
		if (!var)
			var = ft_strdup("");
		temp = var;
		var = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (var);
}

char	*ft_check(char	*str)
{
	size_t		len;
	char		*var;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	var = ft_substr(str, len + 1, ft_strlen(str) - len);
	if (*var == '\0')
	{
		free(var);
		var = NULL;
	}
	str[len + 1] = '\0';
	return (var);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*str;
	static char	*var[256];
	size_t		buffer;

	buffer = (size_t)BUFFER_SIZE;
	if (fd < 0 || buffer <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (buffer + 1));
	if (!buf)
		return (NULL);
	str = readfile(fd, buf, var[fd]);
	free (buf);
	buf = NULL;
	if (!str)
		return (NULL);
	var[fd] = ft_check(str);
	return (str);
}
// int main()
// {

// 	int fd1;
// 	int fd2;
// 	char *s1;
// 	char *s2;
// 	// int a = 0;

// 	fd1 = open("fd1.txt", O_RDONLY);
// 	fd2 = open("fd2.txt", O_RDONLY);
// 	while(1)
// 	{
// 		s1 = get_next_line(fd1);
// 		s2 = get_next_line(fd2);

// 		printf("%s|", s1);
// 		printf("%s|", s2);

// 		if(!s1 || !s2)
// 		{
// 			// printf("not s");
// 		 	break;
// 		}
// 		free(s1);
// 		free(s2);
// 		// a++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return(0);
// }
