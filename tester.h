/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:16:41 by yuna              #+#    #+#             */
/*   Updated: 2024/04/17 18:36:42 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"

# define ALL 0
# define MANDATORY 1
# define BONUS 2
# define TEST 3

# define PRT printf("["); ret = printf
# define ENDPRT printf("] %d\n", ret)

# define FRT ft_printf("["); ret = ft_printf
# define ENDFRT ft_printf("] %d\n", ret)

# define STR "%c", 'a'
# define FUNC(X) PRT(X); ENDPRT

// %c
# define CHR_M_1 "%c", 'a'
# define CHR_M_2 "%c", 'X'

# define CHR_B_1 "%3c", 's'
# define CHR_B_2 "%-3c", 'h'

// %s
# define STR_M_1 "%s", "Hello I'm yuna."

# define STR_B_1 "%-20s", "I love lying on the bed."
# define STR_B_2 "%10s", "halp me"
# define STR_B_3 "%3s", "ya-hoo"

// %p
# define PTR_M_1 "%p", &ret
# define PTR_M_2 "%p", (void *)-1

// %d
# define D_INT_M_1 "%d", 0
# define D_INT_M_2 "%d", -1
# define D_INT_M_3 "%d", 10
# define D_INT_M_4 "%d", 9
# define D_INT_M_5 "%d", -124
# define D_INT_M_6 "%d", (int)-2147483648
# define D_INT_M_7 "%d", (int)2147483648
# define D_INT_M_8 "%d", (int)2147483647

// %i
# define I_INT_M_1 "%i", 0
# define I_INT_M_2 "%i", -1
# define I_INT_M_3 "%i", 10
# define I_INT_M_4 "%i", 9
# define I_INT_M_5 "%i", -124
# define I_INT_M_6 "%i", (int)-2147483648
# define I_INT_M_7 "%i", (int)2147483648
# define I_INT_M_8 "%i", (int)2147483647

// %u
# define UINT_M_1 "%i", 0
# define UINT_M_2 "%i", -1
# define UINT_M_3 "%i", 10
# define UINT_M_4 "%i", 9
# define UINT_M_5 "%i", -124
# define UINT_M_6 "%i", (int)-2147483648
# define UINT_M_7 "%i", (int)2147483648
# define UINT_M_8 "%i", (int)2147483647

// %x
# define LOWER_X_M_1 "%x", 0
# define LOWER_X_M_2 "%x", -1
# define LOWER_X_M_3 "%x", -42

// %X
# define UPPER_X_M_1 "%X", 0
# define UPPER_X_M_2 "%X", -1
# define UPPER_X_M_3 "%X", -42

int	print_all(int mode);

#endif