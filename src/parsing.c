/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:01 by eric              #+#    #+#             */
/*   Updated: 2026/03/06 16:52:24 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

void parse_args(int ac, char *av[], t_nmap *nmap)
{
	if (ac != 3)
	{
		fprintf(stderr, "Usage: ./ft_nmap <ip> <port>\n");
		exit (1);
	}

	strncpy(nmap->target_ip, av[1], 15); // -> copie ip dans target ip
	nmap->target_ip[15] = '\0';

	nmap->ports[0] = atoi(av[2]);
	nmap->port_count = 1;
}
