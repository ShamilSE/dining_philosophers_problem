/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:40:07 by mismene           #+#    #+#             */
/*   Updated: 2020/12/04 20:58:44 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	ft_tolower(int c)
{
	return ((c >= 65 && c < 91) ? (c + 32) : (c));
}