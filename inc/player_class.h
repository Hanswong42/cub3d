/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_class.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:44:41 by nfernand          #+#    #+#             */
/*   Updated: 2022/09/02 14:21:17 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
# define PLAYER_CLASS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# include "map_class.h"
# include "structs.h"
# include "macros.h"
# include "utils.h"

typedef struct s_player	t_player;
typedef struct s_map	t_map;

typedef void			(*t_move_player)(t_player *self,
							int keycode, t_map *map);
typedef void			(*t_turn_player)(t_player *self, int keycode);
typedef void			(*t_print_player)(t_player *self);
typedef void			(*t_turn_player_mouse)(t_player *self, double m_pos);

struct			s_player
{
	t_move_player		move_player;
	t_turn_player		turn_player;
	t_print_player		print_player;
	t_turn_player_mouse	turn_player_mouse;
	t_vec				pos;
	t_vec				ray_dir;
	t_vec				plane_dir;
	double				direction;
	int					size;
};

t_player		player_init(t_coord player_pos, int player_direction);
void			move_player(t_player *self, int keycode, t_map *map);
void			turn_player(t_player *self, int keycode);
void			print_player(t_player *self);
void			turn_player_mouse(t_player *self, double m_pos);

t_vec			get_player_direction_angle(int player_direction);
t_vec			get_plane_dir(t_vec ray_dir);
int				validate_move(t_player *player, t_map *map, int keycode);
void			turn_player_arrow_keys(t_player *player, int keycode);

#endif
