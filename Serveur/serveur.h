/*
** serveur.h for Zap in /home/gonon_c/Desktop/PSU_2013_zappy/Serveur
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 13:47:07 2014 gonon_c
** Last update Sun Jul  6 13:56:02 2014 gonon_c
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "world.h"

# define MAX_CLIENT 255
# define FREE 1
# define NOFREE 0

# define NOINIT 0
# define INIT 1
# define GRAPHIC 2

# define FOOD 0
# define LINEMATE 1
# define DERAUMERE 2
# define SIBUR 3
# define MENDIANE 4
# define PHIRAS 5
# define THYSTAME 6
# define PLAYER 7
# define EGGS 8

typedef struct		s_client
{
  int			id;
  int			init;
  char			free;
}			t_client;

typedef struct		s_serveur
{
  struct sockaddr_in	sin;
  t_client		ctab[MAX_CLIENT]; // a changer par t_client *ctab = malloc(maxClient)
  int			idmax; // le nombre de joueur connecter
  int			maxClient;
  int			maxClientbyTeam;
  int			isRuning;
  int			fd_max;
  int			fd;  
  int			fdMonitor; // changer par list chainée 
}			t_serveur;

typedef struct          s_team
{
  char                  *data;
  struct s_team         *next;
}                       t_team;

typedef struct		s_option
{
  int			port;
  int			worldX;
  int			worldY;
  t_team		*team;
  int			maxClientbyTeam;
  int			t;
}			t_option;

int			opt_p(t_option *option, char **av, int *i);
int			opt_x(t_option *option, char **av, int *i);
int			opt_y(t_option *option, char **av, int *i);
int			opt_c(t_option *option, char **av, int *i);
int			opt_t(t_option *option, char **av, int *i);
int			opt_n(t_option *option, char **av, int *i);
void			add_client(t_serveur *);
int			init_serveur(t_serveur *, t_option *);
int			init_world(t_world *, t_option *);
int			initGraphMonitor(t_world *, int);
int			send_msg(int, char *);
int			send_msgToAll(t_serveur *, char *);
int			send_msgToAll_exeptOne(t_serveur *, char *, int);

#endif /* !SERVEUR_H_ */
