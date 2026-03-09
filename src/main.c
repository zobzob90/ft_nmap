/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:42:53 by eric              #+#    #+#             */
/*   Updated: 2026/03/08 10:36:48 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

int main(int ac, char *av[])
{
	t_nmap nmap;
	
	memset(&nmap, 0, sizeof (t_nmap));				// init de la struct a 0
	
	pthread_mutex_init(&nmap.print_mutex, NULL);
	parse_args(ac, av, &nmap);						// parsing des arguments

	if (nmap.nb_threads > 0)
		start_threads(&nmap);
	else
		start_scanning(&nmap);						// scanne des ports

	pthread_mutex_destroy(&nmap.print_mutex);
	return (0);
}
