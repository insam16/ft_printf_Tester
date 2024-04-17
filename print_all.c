/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:16:45 by yuna              #+#    #+#             */
/*   Updated: 2024/04/17 12:18:17 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	int		mode = ALL;
	char	state = 'p';

	int		ret1 = 0;
	int		ret2 = 0;

	int		fd_prt = open("fd_prt", O_WRONLY|O_CREAT|O_TRUNC, 777);
	int		fd_frt = open("fd_frt", O_WRONLY|O_CREAT|O_TRUNC, 777);
	int		temp_fd = dup(fd_prt);
	
	dup2(fd_prt, STDOUT_FILENO);
	
	while (1)
	{
		//
		if (mode == MANDATORY || mode == ALL)
		{
			// mandatory 세리머니

			// %c
			FUNC(CHR_M_1);
			FUNC(CHR_M_2);

			FUNC(CHR_B_1);
			FUNC(CHR_B_2);

			// %s
			FUNC(STR_M_1);

			FUNC(STR_B_1);
			FUNC(STR_B_2);
			FUNC(STR_B_3);

			// %p
			FUNC(PTR_M_1);
			FUNC(PTR_M_2);

			// %d
			FUNC(D_INT_M_1);
			FUNC(D_INT_M_2);
			FUNC(D_INT_M_3);
			FUNC(D_INT_M_4);
			FUNC(D_INT_M_5);
			FUNC(D_INT_M_6);
			FUNC(D_INT_M_7);
			FUNC(D_INT_M_8);

			// %i
			FUNC(I_INT_M_1);
			FUNC(I_INT_M_2);
			FUNC(I_INT_M_3);
			FUNC(I_INT_M_4);
			FUNC(I_INT_M_5);
			FUNC(I_INT_M_6);
			FUNC(I_INT_M_7);
			FUNC(I_INT_M_8);

			// %u
			FUNC(UINT_M_1);
			FUNC(UINT_M_2);
			FUNC(UINT_M_3);
			FUNC(UINT_M_4);
			FUNC(UINT_M_5);
			FUNC(UINT_M_6);
			FUNC(UINT_M_7);
			FUNC(UINT_M_8);

			// %x
			FUNC(LOWER_X_M_1);
			FUNC(LOWER_X_M_2);
			FUNC(LOWER_X_M_3);

			// %X
			FUNC(UPPER_X_M_1);
			FUNC(UPPER_X_M_2);
			FUNC(UPPER_X_M_3);
		}
		if (mode == BONUS || mode == ALL)
		{
			// bonus 세리머니

			// %c
			FUNC(CHR_B_1);
			FUNC(CHR_B_2);

			// %s
			FUNC(STR_B_1);
			FUNC(STR_B_2);
			FUNC(STR_B_3);

			// %p
			/*
			FUNC(PTR_M_1);
			FUNC(PTR_M_2);

			// %d
			FUNC(D_INT_M_1);
			FUNC(D_INT_M_2);
			FUNC(D_INT_M_3);
			FUNC(D_INT_M_4);
			FUNC(D_INT_M_5);
			FUNC(D_INT_M_6);
			FUNC(D_INT_M_7);
			FUNC(D_INT_M_8);

			// %i
			FUNC(I_INT_M_1);
			FUNC(I_INT_M_2);
			FUNC(I_INT_M_3);
			FUNC(I_INT_M_4);
			FUNC(I_INT_M_5);
			FUNC(I_INT_M_6);
			FUNC(I_INT_M_7);
			FUNC(I_INT_M_8);

			// %u
			FUNC(UINT_M_1);
			FUNC(UINT_M_2);
			FUNC(UINT_M_3);
			FUNC(UINT_M_4);
			FUNC(UINT_M_5);
			FUNC(UINT_M_6);
			FUNC(UINT_M_7);
			FUNC(UINT_M_8);

			// %x
			FUNC(LOWER_X_M_1);
			FUNC(LOWER_X_M_2);
			FUNC(LOWER_X_M_3);

			// %X
			FUNC(UPPER_X_M_1);
			FUNC(UPPER_X_M_2);
			FUNC(UPPER_X_M_3);
			*/
		}
		
		if (state == 'p')
		{
			state = 'f';
			fflush(stdout);
			dup2(fd_prt, temp_fd);
			close(fd_prt);

			temp_fd = dup(fd_frt);
			dup2(fd_frt, STDOUT_FILENO);

			#undef FUNC
			#define FUNC(X) PRT(X); ENDPRT
		}
		else
		{
			fflush(stdout);
			dup2(fd_frt, temp_fd);
			close(fd_frt);
			break;
		}
	}
	return (0);
}
