/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:05 by eric              #+#    #+#             */
/*   Updated: 2026/03/06 16:58:58 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

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

void	start_scanning(t_nmap *nmap)
{
	int	sock;
	struct sockaddr_in addr;

	sock = create_socket();

	addr.sin_family = AF_INET;
	addr.sin_port = htons(nmap->ports[0]);
	inet_pton(AF_INET, nmap->target_ip, &addr.sin_addr);
	
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0)
		printf("Port %d: OPEN\n", nmap->ports[0]);
	else
		printf("Port %d: CLOSE\n", nmap->ports[0]);
	close(sock);	
}
