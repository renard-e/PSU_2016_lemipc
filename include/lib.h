/*
** lib.h for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_lemipc/include
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Mon Mar 20 10:17:42 2017 Gregoire Renard
** Last update Sun Apr  2 23:40:36 2017 Gregoire Renard
*/

#ifndef LIB_H_
# define LIB_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <ncurses.h>
# include <pthread.h>

# define ERROR -1
# define SUCCESS 0
# define X 30
# define Y 30
# define MAX 9
# define COLOR_BROWN x
# define COLOR_REAL_YELLOW y
# define MAX_MSG 5

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_info
{
  int			team_number;
  key_t			key;
  int			shm_id;
  int			sem_id;
  int			msg_id;
  char			*path;
  char			*map_line;
  int			n_team;
}			t_info;

typedef struct		s_team
{
  int			nb_player;
  int			n_team;
  int			team_number;
}			t_team;

typedef struct		s_msg
{
  int			n_team;
  t_pos			pos_target;
  long			mtype;
}			t_msg;

typedef struct		s_gateway
{
  t_msg			msg[MAX_MSG];
}			t_gateway;

typedef struct		s_global
{
  int			nb_team;
  t_team		all_team[MAX];
  t_gateway		gate[MAX];
}			t_global;

int			fill_info(t_info *info, char **argv, int argc);
int			set_map(t_info *info);
void			print_map(char *map);
int			printf_error(char *error);
int			all_process(t_info *info);
int			set_all(t_info *info);
void			free_info(t_info *info);
char			get_char_map(t_info *info, int const x, int const y);
void			set_char_map(t_info *info, int const x,
				     int const y, char const value);
void			mov_char_map(t_info *info, t_pos const pos_start,
				     t_pos const pos_end);
int			start_work(t_info *info, t_global *global);
void			pop(t_info *info, t_global *global, t_pos *my_pos);
void		        move_pos(t_info *info, t_global *global, t_pos *my_pos);
int			print_map_ncurses(char const *map);
char			*convert_in_char(int nb);
int			init_or_end(t_global *global,
				    int *ret, int indic);
int			create_shared_memory(t_info *info, t_global **global);
int			create_semaphore(t_info *info);
int			create_msg(t_info *info);
int			inc_semaphore(t_info *info);
int			dec_semaphore(t_info *info);
int			get_shm(t_info *info, t_global **global);
int			get_sem(t_info *info);
int			get_msg(t_info *info);
int			attack(t_info *info,
			       t_global *global,
			       t_pos *my_pos, t_pos *new_pos);
void			send_sms(t_info *info,
				 t_pos *my_pos, int n_team);
void			rec_sms(t_info *info, t_global *global);
int			check_enemy(char *enemy, char my_char);
void			init_enemy(char *enemy);
void			*restart_first(void *arg);

#endif /* !LIB_H_ */
