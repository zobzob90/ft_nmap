/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:05 by eric              #+#    #+#             */
/*   Updated: 2026/03/07 17:32:52 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

int		scan_port(t_nmap *nmap, int port)
{
	int					sock;
	struct sockaddr_in	addr;
	fd_set				wset;
	struct timeval		tv;
	int					ret;

	sock = create_socket();
	
	fcntl(sock, F_SETFL, O_NONBLOCK);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	inet_pton(AF_INET, nmap->target_ip, &addr.sin_addr);
	
	connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	
	FD_ZERO(&wset);
	FD_SET(sock, &wset);
	tv.tv_sec = 1;
	tv.tv_usec = 0;

	ret = select(sock + 1, NULL, &wset, NULL, &tv);
	close(sock);

	if (ret > 0)
		return (OPEN);
	return (CLOSE);
}

void	start_scanning(t_nmap *nmap)
{
	int status;
	
	for(int i = 0; i < nmap->port_count; i++)
	{
		status = scan_port(nmap, nmap->ports[i]);
		if (status == OPEN)
			printf("Port %d: OPEN\n", nmap->ports[i]);
		else
			printf("Port %d: CLOSE\n", nmap->ports[i]);	
	}	
}
