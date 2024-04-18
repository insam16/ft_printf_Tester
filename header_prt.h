/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_prt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:12:16 by yuna              #+#    #+#             */
/*   Updated: 2024/04/18 10:23:49 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PRT_H
# define HEADER_PRT_H

# define FILENAME "result_printf"
# define PRT printf("["); ret = printf
# define ENDPRT printf("] %d\n", ret)
# define FUNC(X) PRT(X); ENDPRT
# define PRINT printf

#endif
