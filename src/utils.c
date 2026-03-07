/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:08 by eric              #+#    #+#             */
/*   Updated: 2026/03/07 17:14:40 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

void	resolve_host(char *host, t_nmap *nmap)
{
	struct addrinfo	hints;
	struct addrinfo *res;

	strncpy(nmap->hostname, host, 255);
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;

	if (getaddrinfo(host, NULL, &hints, &res) != 0)
	{
		fprintf(stderr, "Error: cannot resolve %s\n", host);
		exit (1);
	}
	
	inet_ntop(AF_INET, &((struct sockaddr_in *)res->ai_addr)->sin_addr, nmap->target_ip, sizeof(nmap->target_ip));
	freeaddrinfo(res);
}
