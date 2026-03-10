/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:54:19 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/03 17:01:52 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	if (a > b)
		return (b);
	return (0);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	if (a < b)
		return (b);
	return (0);
}

int	ft_va(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}
