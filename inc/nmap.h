/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:43:11 by eric              #+#    #+#             */
/*   Updated: 2026/03/07 17:15:01 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMAP_H
#define NMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>

#include <arpa/inet.h>
#include <pthread.h>

#define OPEN 1
#define CLOSE 2

typedef struct s_nmap
{
	char	target_ip[16];		// stocke ip cible
	char	hostname[256];		// hostname original (ex: google.com)
	int		ports[65365];		// tableau des ports a scanner
	int		port_count;			// nombre de ports a scanner
} t_nmap;

/*PARSING*/
void	parse_args(int ac, char *av[], t_nmap *nmap);

/*SCANNING*/
int		create_socket();
void	start_scanning(t_nmap *nmap);

/*UTILS*/
void	resolve_host(char *host, t_nmap *nmap);

#endif