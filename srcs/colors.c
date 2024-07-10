/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:45:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 08:35:07 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	red(int *gradient);

static void	green(int *gradient);

static void	blue(int *gradient);

static void	purple(int *gradient);

void	get_gradient(t_data data, int *gradient)
{
	if (data.gradient % 10 == 0)
		green(gradient);
	if (data.gradient % 10 == 1)
		red(gradient);
	if (data.gradient % 10 == 2)
		blue(gradient);
	if (data.gradient % 10 == 3)
		purple(gradient);
	if (data.gradient % 10 == 4)
		green(gradient);
	if (data.gradient % 10 == 5)
		red(gradient);
	if (data.gradient % 10 == 6)
		blue(gradient);
	if (data.gradient % 10 == 7)
		purple(gradient);
	if (data.gradient % 10 == 8)
		green(gradient);
	if (data.gradient % 10 == 9)
		red(gradient);
}

static void	green(int *gradient)
{
	gradient[0] = GREEN_0;
	gradient[1] = GREEN_1;
	gradient[2] = GREEN_2;
	gradient[3] = GREEN_3;
	gradient[4] = GREEN_4;
	gradient[5] = GREEN_5;
	gradient[6] = GREEN_6;
	gradient[7] = GREEN_7;
	gradient[8] = GREEN_8;
	gradient[9] = GREEN_9;
}

static void	red(int *gradient)
{
	gradient[0] = RED_0;
	gradient[1] = RED_1;
	gradient[2] = RED_2;
	gradient[3] = RED_3;
	gradient[4] = RED_4;
	gradient[5] = RED_5;
	gradient[6] = RED_6;
	gradient[7] = RED_7;
	gradient[8] = RED_8;
	gradient[9] = RED_9;
}

static void	blue(int *gradient)
{
	gradient[0] = BLUE_0;
	gradient[1] = BLUE_1;
	gradient[2] = BLUE_2;
	gradient[3] = BLUE_3;
	gradient[4] = BLUE_4;
	gradient[5] = BLUE_5;
	gradient[6] = BLUE_6;
	gradient[7] = BLUE_7;
	gradient[8] = BLUE_8;
	gradient[9] = BLUE_9;
}

static void	purple(int *gradient)
{
	gradient[0] = PURPLE_0;
	gradient[1] = PURPLE_1;
	gradient[2] = PURPLE_2;
	gradient[3] = PURPLE_3;
	gradient[4] = PURPLE_4;
	gradient[5] = PURPLE_5;
	gradient[6] = PURPLE_6;
	gradient[7] = PURPLE_7;
	gradient[8] = PURPLE_8;
	gradient[9] = PURPLE_9;
}