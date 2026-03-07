/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:42:53 by eric              #+#    #+#             */
/*   Updated: 2026/03/07 17:05:48 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

int main(int ac, char *av[])
{
	t_nmap nmap;
	
	memset(&nmap, 0, sizeof (t_nmap));		// init de la struct a 0
	parse_args(ac, av, &nmap);				// parsing des arguments
	start_scanning(&nmap);					// scanne des ports

	return (0);
}
