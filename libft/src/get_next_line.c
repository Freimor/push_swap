/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:32 by ojessi            #+#    #+#             */
/*   Updated: 2020/04/08 10:04:57 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_n_0(char *str) //можно ускорить путем strchr
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static t_list	*listcreate(t_list **stack, const int fd)
{
	t_list *s;

	if (*stack == NULL)
	{
		*stack = ft_lstnew("\0", fd);
		return (*stack);
	}
	if ((s = ft_lstcheck_contentsize(stack, fd)) == 0)
	{
		s = ft_lstnew("\0", fd);
		ft_lstadd(stack, s);
	}
	return (s);
}

static int		reading_to_n(const int fd, t_list **stack)
{
	int		ret;
	int		count;
	t_list	*buf;
	char	*tmp;
	char	str[BUFF_SIZE + 1];

	ret = BUFF_SIZE;
	tmp = "";
	count = 0;
	while ((ft_strchr(tmp, '\n')) == NULL && ret == BUFF_SIZE)
	{
		if ((ret = read(fd, str, BUFF_SIZE)) > 0)
		{
			buf = listcreate(stack, fd);
			str[ret] = '\0';
			tmp = ft_strjoin(buf->content, str);
			free(buf->content);
			buf->content = tmp;
		}
		count += ret;
	}
	return (count);
}

static int		linef(t_list **stack, char **line, const int fd)
{
	char	*tmp;
	char	*content;
	int		i;
	t_list	*search;

	search = listcreate(stack, fd);
	content = search->content;
	i = check_n_0(content);
	if (content[i] == '\n')
	{
		*line = ft_strsub(content, 0, i);
		tmp = ft_strdup(content + i + 1);
		free(search->content);
		search->content = ft_strdup(tmp);
		if (tmp[0] == '\0')
			ft_lstdel_contentsize(stack, fd);
		free(tmp);
	}
	else if (content[i] == '\0')
	{
		*line = ft_strdup(content);
		ft_lstdel_contentsize(stack, fd);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*stack;
	int				count;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if ((fd < 0) || (line == NULL) || read(fd, buf, 0) < 0)
		return (-1);
	count = reading_to_n(fd, &stack);
	if (count == -1)
		return (-1);
	if (count == 0 && (ft_lstcheck_contentsize(&stack, fd) == NULL))
		return (0);
	ret = linef(&stack, line, fd);
	return (ret);
}