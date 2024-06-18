/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:10:03 by quenalla          #+#    #+#             */
/*   Updated: 2024/06/18 12:22:38 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_strcount(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	unsigned long int	nb;
	unsigned long int	compteur;
	int					len;

	nb = n;
	len = ft_strcount(nb);
	compteur = 1;
	if (nb == 0)
		return (ft_printchar('0'));
	while (compteur <= nb)
		compteur = compteur * 10;
	while (compteur != 1)
	{
		compteur = compteur / 10;
		ft_printchar(nb / compteur + '0');
		nb = nb % compteur;
	}
	return (len);
}
