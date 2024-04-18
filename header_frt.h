/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_frt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:11:30 by yuna              #+#    #+#             */
/*   Updated: 2024/04/18 10:23:46 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_FRT_H
# define HEADER_FRT_H

# define FILENAME "result_ft_printf"
# define FRT ft_printf("["); ret = ft_printf
# define ENDFRT ft_printf("] %d\n", ret)
# define FUNC(X) FRT(X); ENDFRT
# define PRINT ft_printf

#endif
