/*
** sms.c for lemipc in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_lemipc/src
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Sat Apr  1 13:29:51 2017 Rodrigue René
** Last update Sun Apr  2 20:08:40 2017 Rodrigue RENE
*/

#include "lib.h"

void		rec_sms(t_info *info, t_global *global)
{
  t_msg		sms;
  int		x;

  x = (int)msgrcv(info->msg_id, &sms, sizeof(sms), 1, IPC_NOWAIT);
  if (x != -1)
    {
      x = 0;
      while (x < (MAX_MSG - 1))
	{
	  if (global->gate[sms.n_team].msg[x].n_team == -1)
	    {
	      global->gate[sms.n_team].msg[x].pos_target.x = sms.pos_target.x;
	      global->gate[sms.n_team].msg[x].pos_target.y = sms.pos_target.y;
	      global->gate[sms.n_team].msg[x].n_team = sms.n_team;
	      x = MAX_MSG;
	    }
	  ++x;
	}
    }
}

void		send_sms(t_info *info,
			 t_pos *my_pos, int n_team)
{
  t_msg		sms;

  sms.pos_target.x = my_pos->x;
  sms.pos_target.y = my_pos->y;
  sms.n_team = n_team;
  sms.mtype = 1;
  msgsnd(info->msg_id, &sms, sizeof(sms), IPC_NOWAIT);
}
