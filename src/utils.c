/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:08 by eric              #+#    #+#             */
/*   Updated: 2026/03/09 10:03:10 by eric             ###   ########.fr       */
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

int	create_socket()
{
	int	sock;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("socket failed");
		exit (1);
	}

	return (sock);
}

void	print_help()
{
	printf("Help screen\n");
	printf("ft_nmap [OPTIONS]\n");
	printf("--help		Print this help screen\n");
	printf("--ports		ports to scan (eg: 1-10 or 1,2,3 or 1,5-15\n");
	printf("--ip		ip addresses to scan in dot format\n");
	printf("--file		File name containing IP addresses to scan\n");
	printf("--speedup	[250 max] number of parallel threads to use\n");
	printf("--scan		SYN/NULL/FIN/XMAS/ACK/UDP\n");
}
