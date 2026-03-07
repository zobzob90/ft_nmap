/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:01 by eric              #+#    #+#             */
/*   Updated: 2026/03/07 17:15:30 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

static void parse_port_range(char *av, t_nmap *nmap)
{
	char	*dash;
	int		start;
	int		end;
	int		i;

	dash = strchr(av, '-');
	if (dash)
	{
		*dash = '\0';
		start = atoi(av);
		end = atoi(dash + 1);
		i = 0;
		while (start <= end)
			nmap->ports[i++] = start++;
		nmap->port_count = i;
	}
	else
	{
		nmap->ports[0] = atoi(av);
		nmap->port_count = 1;
	}
}

void parse_args(int ac, char *av[], t_nmap *nmap)
{
	if (ac != 3)
	{
		fprintf(stderr, "Usage: ./ft_nmap <ip> <port>\n");
		exit (1);
	}

	resolve_host(av[1], nmap);
	nmap->target_ip[15] = '\0';
	parse_port_range(av[2], nmap);
}

