/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:31:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/23 23:34:15 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_failure(void)
{
	exit(EXIT_FAILURE);
}

void	exit_free(void *data)
{
	free(data);
	exit_failure();
}