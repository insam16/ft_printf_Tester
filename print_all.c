/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:16:45 by yuna              #+#    #+#             */
/*   Updated: 2024/04/18 12:35:43 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int		print_all(int mode)
{
	int		ret = 0;
	int		fd = open(FILENAME, O_WRONLY|O_CREAT|O_TRUNC, 777);
	int		temp_fd = dup(fd);
	int		saved_stdout = dup(STDOUT_FILENO);

	dup2(fd, STDOUT_FILENO);
	
	if (mode == MANDATORY || mode == ALL)
	{
		print_section('m');

		// %c
		print_conversion('c');
		FUNC(CHR_M_1);
		FUNC(CHR_M_2);

		// %s
		print_conversion('s');
		FUNC(STR_M_1);

		// %p
		print_conversion('p');
		FUNC(PTR_M_1);
		FUNC(PTR_M_2);

		// %d
		print_conversion('d');
		FUNC(D_INT_M_1);
		FUNC(D_INT_M_2);
		FUNC(D_INT_M_3);
		FUNC(D_INT_M_4);
		FUNC(D_INT_M_5);
		FUNC(D_INT_M_6);
		FUNC(D_INT_M_7);
		FUNC(D_INT_M_8);

		// %i
		print_conversion('i');
		FUNC(I_INT_M_1);
		FUNC(I_INT_M_2);
		FUNC(I_INT_M_3);
		FUNC(I_INT_M_4);
		FUNC(I_INT_M_5);
		FUNC(I_INT_M_6);
		FUNC(I_INT_M_7);
		FUNC(I_INT_M_8);

		// %u
		print_conversion('u');
		FUNC(UINT_M_1);
		FUNC(UINT_M_2);
		FUNC(UINT_M_3);
		FUNC(UINT_M_4);
		FUNC(UINT_M_5);
		FUNC(UINT_M_6);
		FUNC(UINT_M_7);
		FUNC(UINT_M_8);

		// %x
		print_conversion('x');
		FUNC(LOWER_X_M_1);
		FUNC(LOWER_X_M_2);
		FUNC(LOWER_X_M_3);

		// %X
		print_conversion('X');
		FUNC(UPPER_X_M_1);
		FUNC(UPPER_X_M_2);
		FUNC(UPPER_X_M_3);
	}
	if (mode == BONUS || mode == ALL)
	{
		print_section('b');

		// %c
		print_conversion('c');
		FUNC(CHR_B_1);
		FUNC(CHR_B_2);

		// %s
		print_conversion('s');
		FUNC(STR_B_1);
		FUNC(STR_B_2);
		FUNC(STR_B_3);

		// %p
		print_conversion('p');
		/*
		FUNC(PTR_B_1);
		FUNC(PTR_B_2);

		// %d
		print_conversion('d');
		FUNC(D_INT_B_1);
		FUNC(D_INT_B_2);
		FUNC(D_INT_B_3);
		FUNC(D_INT_B_4);
		FUNC(D_INT_B_5);
		FUNC(D_INT_B_6);
		FUNC(D_INT_B_7);
		FUNC(D_INT_B_8);

		// %i
		print_conversion('i');
		FUNC(I_INT_B_1);
		FUNC(I_INT_B_2);
		FUNC(I_INT_B_3);
		FUNC(I_INT_B_4);
		FUNC(I_INT_B_5);
		FUNC(I_INT_B_6);
		FUNC(I_INT_B_7);
		FUNC(I_INT_B_8);

		// %u
		print_conversion('u');
		FUNC(UINT_B_1);
		FUNC(UINT_B_2);
		FUNC(UINT_B_3);
		FUNC(UINT_B_4);
		FUNC(UINT_B_5);
		FUNC(UINT_B_6);
		FUNC(UINT_B_7);
		FUNC(UINT_B_8);

		*/
		// %x
		print_conversion('x');
		FUNC(LOWER_X_B_1);
		FUNC(LOWER_X_B_2);
		FUNC(LOWER_X_B_3);

		// %X
		print_conversion('X');
		FUNC(UPPER_X_B_1);
		FUNC(UPPER_X_B_2);
		FUNC(UPPER_X_B_3);
	}
	
	fflush(stdout);
	dup2(fd, temp_fd);
	close(fd);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	
	return (0);
}

void	print_conversion(char ch)
{
	PRINT("\n=======================\n");
	PRINT("===       %%%c        ===\n", ch);
	PRINT("=======================\n");
}

void	print_section(char ch)
{
	if (ch == 'b')
		PRINT("\n\n");
	PRINT("================= ");
	if (ch == 'm')
		PRINT("mandatory");
	else
		PRINT("bonus");
	PRINT(" part =================\n\n");
}
