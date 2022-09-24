#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#include "get_next_line.h"

static	int	ft_is_nl(char *str)
{
	int	i;

	i = 0;
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
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*container[1024];

	if (container[fd] == NULL)
		container[fd] = (char *) malloc (sizeof(char*));
	if (!container[fd])
		return (NULL);
	if (ft_is_nl(container[fd]))
		return (ft_send_nl(container[fd], container, fd));

}

int main()
{
	get_next_line(100);
}
