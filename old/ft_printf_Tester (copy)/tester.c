/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:16:37 by yuna              #+#    #+#             */
/*   Updated: 2024/04/18 09:24:23 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	tester_strcmp(unsigned char *s1, unsigned char *s2);
//https://medium.com/@selvarajk/adding-color-to-your-output-from-c-58f1a4dc4e75
int	main(void)
{
	int		mode = ALL;
	int		fd_prt;
	int		fd_frt;
	char	*line1 = "";
	char	*line2 = "";

	print_all(mode);

	fd_prt = open("fd_prt", O_RDONLY);
	fd_frt = open("fd_frt", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd_prt);
		line2 = get_next_line(fd_frt);

		if (!line1 && !line2)
			break ;

		if (line1[0] == '\n')
			continue;
		if (line1[2] == '=')
		{
			if (line1[4] == '=')
			{
				printf("\033[1;37m"); //white bold
				if (line1[18] == 'm')
					print_section('m');
				else if (line1[18] == 'b')
				{
					printf("\n\n");
					print_section('b');
				}
			}
			else if (line1[3] == ' ')
			{
				printf("\033[0;37m"); //white
				printf("\n");
				print_conversion(line1[11]);
			}
			else if (line1[3] == '=')
			{
				continue ;
			}
		}
		else if (tester_strcmp((unsigned char *)line1, (unsigned char *)line2))
		{
			printf("\033[0;31m"); //red
			printf("[KO]\n");
			printf("   printf: %s\n", line1);
			printf("ft_printf: %s\n", line2);
		}
		else
		{
			printf("\033[0;32m"); //green
			printf("[OK]");
		}

		if (line1)
			free(line1);
		if (line2)
			free(line2);
	}
	close(fd_prt);
	close(fd_frt);
	// unlink("fd_prt");
	unlink("fd_frt");
	return (0);
}

int	tester_strcmp(unsigned char *s1, unsigned char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}
