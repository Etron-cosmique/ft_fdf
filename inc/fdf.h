/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:54:02 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/13 17:36:43 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define LOG    printf("%s:%d %s()\n", __FILE__,__LINE__, __FUNCTION__);
# define DEBUG 1
# define PAUSE    if (DEBUG) {getchar();};

# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data {
	void 	*img_ptr;
	char 	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_data;

typedef struct s_line {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int dy;
	int	sx;
	int	sy;
	int	flag;
}	t_line;

typedef struct s_math {
	int		index_x;
	int		index_y;
	int		size_x;
	int		size_y;
	int		size_p_x;
	int		size_p_y;
	int		start_x;
	int		start_y;
	int		r_start_x;
	int		r_start_y;
	int		max_alt;
	int		min_alt;
	int		alt_0;
	int		c_alt;
	int		next_alt;
	int		flag;
}	t_math;

typedef struct s_fdf {
	int		fd;
	int		**tab;
	char	*str;
	int		scx;
	int		scy;
	void	*mlx;
	void	*win;
	t_line	l;
	t_data	img;
	t_math	m;
}	t_fdf;

//tools.c
int		is_in_grid(int c_x, int c_y, t_fdf *f);
int		color_maker(t_fdf *f, int x, int y);
void	struct_filler(t_fdf *f);
int		final_color(int x, int y, float ratio, t_fdf *f);
int		next_color(t_fdf *f, char c);


//utils
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int 	get_rgb(int r, int g, int b);
int		width_and_length(t_fdf *f);
int		get_n_col(char *str);
void	l_c_size(t_fdf *f);

// input_utils
int		input_checker(char *str);
int		ft_isdigit(char c);
int		input_maker(t_fdf *f);
int		ft_atoi(const char *str);
int		how_many_d(char *str);

//tools_2.c
void	set_alt(t_fdf *f);
int		prev_color(t_fdf *f);
void	ft_grid(t_fdf *f);
void	set_pix(t_fdf *f, int x, int y);
void	get_pos(int x, int y, t_fdf *f);

//ft_split
char	**ft_split(char const *s, char c);
char	**ft_exit(char **strs);

// shades_and_color.c
int		shade_zero(t_fdf *f, int color);
int		splitter(int color, int flag);
int 	reg_shader(int prev, int next, float ratio);
int		ex_shader(int x, int y, t_fdf *f);
int		x_y(int x, int y, t_fdf *f);

// tools_3.c
void	ft_init(t_fdf *f, char *filename);
void	shut_fdf(t_fdf *f, char *message);
void    ft_bzero(void *s, size_t n);
void	free_tab(int **tab, const int ylen);
int		ft_abs(int i);

// bresenham.c
void	draw_line(t_fdf *f, t_line *l);
void	bresenham(t_fdf *f, int x, int y);
void	get_start_end(t_fdf *f, t_line *l, int x, int y);
int		get_xdest(int x, int y, t_fdf *f);
int		get_ydest(int x, int y, t_fdf *f);

void	printab(t_fdf *f);

void	print_param(t_math *m);

#endif
