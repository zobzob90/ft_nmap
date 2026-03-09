/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:55:39 by eric              #+#    #+#             */
/*   Updated: 2026/03/09 09:57:36 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

void	*thread_scan(void *arg)
{
	t_thread_data	*data;
	int				status;
	int				i;
	
	data = (t_thread_data *)arg;
	i = data->start;
	while (i < data->end)
	{
		status = scan_port(data->nmap, data->nmap->ports[i]);
		pthread_mutex_lock(&data->nmap->print_mutex);
		if (status == OPEN)
			printf("Port %d: OPEN\n", data->nmap->ports[i]);
		pthread_mutex_unlock(&data->nmap->print_mutex);
		i++;
	}
	return (NULL);
}

void	start_threads(t_nmap *nmap)
{
	pthread_t		threads[MAX_THREADS];
	t_thread_data	data[MAX_THREADS];
	int				chunk;
	int				i;

	chunk = nmap->port_count / nmap->nb_threads;
	i = 0;
	while (i < nmap->nb_threads)
	{
		data[i].nmap = nmap;
		data[i].start = i * chunk;
		if (i == nmap->nb_threads - 1)
			data[i].end = nmap->port_count;
		else
			data[i].end = (i + 1) * chunk;
		pthread_create(&threads[i], NULL, thread_scan, &data[i]);
		i++;
	}
	i = 0;
	while (i < nmap->nb_threads)
		pthread_join(threads[i++], NULL);
}
