#ifndef	MAP_CLASS_H
# define MAP_CLASS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>

# include "player_class.h"
# include "structs.h"
# include "macros.h"

typedef struct	c_map		t_map;
typedef struct	c_player	t_player;

typedef	void	(*t_print_map)(t_map *self);
typedef void	(*t_draw_map)(t_map *self, t_player *player);
typedef void	(*t_draw_player_direction)(t_map *self, t_player *player);

struct			c_map
{
	t_draw_map				draw_map;
	t_print_map				print_map;
	t_draw_player_direction draw_player_direction;
	t_img					img;
	t_img					display;
	char					**array;
	int						col;
	int						row;
	int						height;
	int						width;
	int						display_height;
	int						display_width;
	int						flag;
};

t_map   map_init(void *mlx, char *file, t_coord *player_pos, int *player_direction);
void	print_map(t_map *self);
void	draw_map(t_map *self, t_player *player);

#endif
