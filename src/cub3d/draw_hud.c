/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:21:04 by nfernand          #+#    #+#             */
/*   Updated: 2022/08/30 11:14:28 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	draw_hud(t_data *data)
{
	t_xpm	background_tex;
	t_coord	loop;
	int		x_scale;

	init_xpm(data->mlx, &background_tex, "./textures/Steel_2A.xpm");
	x_scale = round((float)data->game.width / XPM_SIZE);
	loop.x = 0;
	while (loop.x < XPM_SIZE * x_scale)
	{
		loop.y = 0;
		while (loop.y < XPM_SIZE * HUD_Y_SCALE)
		{
			if (loop.y % HUD_Y_SCALE == 0)
				data->game.background.data[data->game.width * loop.y + loop.x]
					= background_tex.data[XPM_SIZE
					* (loop.y / HUD_Y_SCALE) + (loop.x / x_scale)];
			else
				data->game.background.data[data->game.width * loop.y + loop.x]
					= background_tex.data[XPM_SIZE
					* ((loop.y - loop.y % HUD_Y_SCALE) / HUD_Y_SCALE)
					+ ((loop.x - loop.x % x_scale) / x_scale)];
			loop.y++;
		}
		loop.x++;
	}
}
