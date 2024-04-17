/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:20:52 by yuna              #+#    #+#             */
/*   Updated: 2024/04/17 19:25:27 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst_head;
	t_list			*lst;
	int				enter_idx;
	ssize_t			ret;
	char			*line;

	lst = gnl_cur_lst(&lst_head, fd);
	if (lst == NULL)
		return (NULL);
	while (1)
	{
		enter_idx = gnl_str_util(lst->backup, UTIL_FIND_ENTER);
		if (enter_idx >= 0)
			return (gnl_make_line(lst, enter_idx, &lst_head));
		ret = read(fd, lst->buff, BUFFER_SIZE);
		line = gnl_do_if_no_read(ret, lst, &lst_head);
		if (line == (char *)BREAK)
			break ;
		else if (line)
			return (line);
		if (gnl_update_backup(ret, lst, &lst_head) == NULL)
			return (NULL);
	}
	return (NULL);
}

void	*gnl_cur_lst(t_list **lst_head, int fd)
{
	t_list	*curr;
	t_list	*lst;

	curr = *lst_head;
	while (curr)
	{
		if (curr->fd == fd)
		{
			lst = curr;
			break ;
		}
		curr = curr->next;
	}
	if (curr)
		return (lst);
	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	gnl_lst_init(lst, fd);
	if (lst->buff == NULL)
		return (NULL);
	if (*lst_head)
		lst->next = *lst_head;
	*lst_head = lst;
	return (lst);
}

char	*gnl_do_if_no_read(ssize_t ret, t_list *lst, t_list **lst_head)
{
	if (ret == RET_ERROR)
	{
		gnl_free_lst(lst_head, lst->fd);
		return ((char *)BREAK);
	}
	if (ret == RET_NOTHING)
	{
		if (lst->backup == NULL || lst->backup[0] == '\0')
		{
			gnl_free_lst(lst_head, lst->fd);
			return ((char *)BREAK);
		}
		else
			return (gnl_make_line(lst, LAST_LINE, lst_head));
	}
	return (NULL);
}

char	*gnl_make_line(t_list *lst, int ret, t_list **lst_head)
{
	char	*line;
	int		len;

	if (ret == LAST_LINE)
	{
		len = gnl_str_util(lst->backup, UTIL_STRLEN);
		line = (char *)malloc(sizeof(char) * (len + 1));
		if (line == NULL)
			return (gnl_free_lst(lst_head, lst->fd));
		line[0] = '\0';
		gnl_lcat(line, lst->backup, len + 1);
		gnl_free_lst(lst_head, lst->fd);
		return (line);
	}
	else
	{
		line = (char *)malloc(sizeof(char) * (ret + 2));
		if (line == NULL)
			return (gnl_free_lst(lst_head, lst->fd));
		line[0] = '\0';
		gnl_lcat(line, lst->backup, ret + 2);
		gnl_lcat(lst->backup, lst->backup + ret + 1, LCAT_MEMMOVE_MODE);
		return (line);
	}
}

char	*gnl_update_backup(ssize_t buff_len, t_list *lst, t_list **lst_head)
{
	int		backup_len;
	char	*temp;

	backup_len = 0;
	while (lst->backup && (lst->backup)[backup_len])
		++backup_len;
	temp = (char *)malloc(sizeof(char) * (buff_len + backup_len + 1));
	if (temp == NULL)
		return (gnl_free_lst(lst_head, lst->fd));
	temp[0] = '\0';
	gnl_lcat(temp, lst->backup, backup_len + 1);
	gnl_lcat(temp, lst->buff, buff_len + 1);
	free(lst->backup);
	lst->backup = temp;
	return (lst->backup);
}

void	*gnl_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		++i;
	}
	return (s);
}

void	gnl_lst_init(t_list *lst, int fd)
{
	gnl_memset(lst, 0, sizeof(t_list));
	lst->fd = fd;
	lst->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
}

void	*gnl_free_lst(t_list **lst_head, int fd)
{
	t_list	*prev;
	t_list	*curr;

	curr = *lst_head;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (curr->backup)
				free(curr->backup);
			if (curr->buff)
				free(curr->buff);
			if (prev == NULL)
				*lst_head = curr->next;
			else
				prev->next = curr->next;
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}

int	gnl_str_util(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == UTIL_STRLEN)
	{
		while (str[i])
			++i;
		return (i);
	}
	else if (mode == UTIL_FIND_ENTER)
	{
		if (str == 0)
			return (-1);
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			++i;
		}
	}
	return (-1);
}

char	*gnl_lcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = -1;
	dst_len = 0;
	if (size == (size_t)LCAT_MEMMOVE_MODE)
	{
		if (src == 0)
			return (gnl_memset(dst, 0, 1));
		while (src[++i])
			dst[i] = src[i];
		dst[i] = '\0';
		return (dst);
	}
	else
	{
		if (src == 0)
			return (dst);
		while (dst[dst_len])
			++dst_len;
		while (src[++i] && i + 1 < size)
			dst[dst_len + i] = src[i];
		dst[dst_len + i] = '\0';
		return (dst);
	}
}
