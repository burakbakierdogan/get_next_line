#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#include "get_next_line.h"


typedef	struct s_get
{
	int		status;// read function return value.
	char	*str;// the string to be returned
	char	*rest;//rest of the string after the newline
}	t_gnl;

static	int	ft_is_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(0);
	while(str[i])
		if (str[i++] == '\n')
			return(1);
	return(0);
}

static	int	ft_lenn(char *str)
{
	int	i;
	if (!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return(i);
}
static	char	*ft_append(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new;

	i = ft_lenn(str1);
	j = ft_lenn(str2);
	new = malloc(sizeof(char) * (i + j + 1));
	i = 0;
	j= 0;
	if (str1)
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	while(str2[j])
		new[i++] = str2[j++];
	new[i] = '\0';
	if (str1)
		free(str1);
	return(new);
}



static	char	*ft_move_rest(char *rest, char *to_free)
{
	int		i;
	char	*new;

	i = 0;
	if (rest[i])
	{
		while (rest[i])
			i++;
		new = malloc((i + 1) * sizeof(char));
		i = -1;
		while(rest[++i])
			new[i] = rest[i];
		new[i] = '\0';
		free(to_free);
		return(new);
	}
	else
	{
		free(to_free);
		return(NULL);
	}
}
static	t_gnl	ft_seperate(char *str, int j)
{
	char	*new;
	int		i;
	t_gnl	ret_val;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	new = (char *) malloc ((i + 2) * sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	ret_val.str = new;
	ret_val.rest = ft_move_rest(str + i, str);
	ret_val.status = j;
	return(ret_val);
}
static	t_gnl	ft_read(char *rest, int fd)
{
	t_gnl	ret_val;
	char	*new;
	int		i;

	i = 2;
	new = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while(i > 0)
	{
		i = read(fd, new, BUFFER_SIZE);
		new[i] = '\0';
		if (ft_is_nl(new))
		{
			rest = ft_append(rest, new);
			break;
		}
		else
		rest = ft_append(rest, new);
	}
	free(new);
	ret_val = ft_seperate(rest, i);
	return(ret_val);
}
char	*get_next_line(int fd)
{
	static char	*container[1024]; // static adress array holder.
	t_gnl		ret_vals; // return values.

	if (ft_is_nl(container[fd]))
	{
		ret_vals = ft_seperate(container[fd], 1);
		container[fd] = ret_vals.rest;
		return(ret_vals.str);
	}
	else
	{
		ret_vals = ft_read(container[fd], fd);
		container[fd] = ret_vals.rest;
	}
	if (!ret_vals.rest && ret_vals.status <= 0)
		return (NULL);
	if (ret_vals.str)
		return(ret_vals.str);
	else if (ret_vals.rest && ret_vals.status <= 0)
		return(ret_vals.rest);
	else	return(NULL);
}

