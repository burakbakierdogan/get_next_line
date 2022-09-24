#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#include "get_next_line.h"


typedef	struct s_get
{
	int		status1;// if the container is empty 0
	int		status2;// if read function returns 0 or -1
	char	*str;// the string to be returned
}	t_gnl;

static	int	ft_is_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

static	char	*ft_rest(char *str)
{
	int			i;
	char	*new;
	i = 0;
	while (str[i])
		i++;
	new = (char *) malloc (sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}
static	char	*ft_send_nl(char *str, char *container[], int fd)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	new = (char *) malloc ((i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i] != '\n')
		new[i] = str[i];
	new[i++] = '\n';
	new[i] = '\0';
	if (str[i])
		container[fd] = ft_rest(str + i);
	//free(str);
	return (new);
}
static	int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
static	char	*ft_append(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	len1 = ft_len(str1);
	len2 = ft_len(str2);
	if (!str1)
		i++;
	new = (char *) malloc (sizeof(char) + (len1 + len2 + 1));
	if (str1 != NULL)
	while (str1[++i])
		new[i] = str1[i];

	while (str2[++j] && str2)
		new[i++] = str2[j];
	new[i] = '\0';
	return (new);
}

static	t_gnl	ft_read(char *container[], int fd)
{
	t_gnl	t_ret;
	char	*new;
	char	*s_container; //second container
	int		i;

	i = 2;
	new = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (container[fd])
		s_container = (container[fd], "");
	free(container[fd]);
	while(i > 0)
	{
		i = read(fd, new, BUFFER_SIZE);
		new[BUFFER_SIZE] = '\0';
		if (ft_is_nl(new))
		{
			s_container = ft_append(s_container, new);
			break;
		}
		else
			 s_container = ft_append(s_container, new);
	}
	free(new);
	t_ret.str = ft_send_nl(s_container, container, fd);
	t_ret.status2 = i;
	t_ret.status1 = (int) *(container[fd]);
	return (t_ret);
}

char	*get_next_line(int fd)
{
	static char	*container[1024];
	t_gnl		t_ret;

	if (ft_is_nl(container[fd]))
		t_ret.str = ft_send_nl(container[fd], container, fd);
	else
	{
		t_ret = ft_read(container, fd);
		if (t_ret.status2 > 0)
			return(t_ret.str);
		if (t_ret.status2 <= 0 && t_ret.status1)
		{
			t_ret.str = container[fd];
			return(t_ret.str);
		}
		else
			return (NULL);
	}
	return (t_ret.str);
}

