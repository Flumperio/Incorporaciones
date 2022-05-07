/* ************************************************************************** */
/*  888888  .d8888b.   .d8888b.                    888                        */ 
/*    "88b d88P  Y88b d88P  Y88b                   888                        */
/*     888 888    888 Y88b.                        888                        */
/*     888 888         "Y888b.    8888b.  88888b.  888888 .d88b.  .d8888b     */
/*     888 888            "Y88b.     "88b 888 "88b 888   d88""88b 88K         */
/*     888 888    888       "888 .d888888 888  888 888   888  888 "Y8888b.    */
/*     88P Y88b  d88P Y88b  d88P 888  888 888  888 Y88b. Y88..88P      X88    */
/*     888  "Y8888P"   "Y8888P"  "Y888888 888  888  "Y888 "Y88P"   88888P'    */
/*   .d88P                                                                    */
/* .d88P"                                                                     */
/*888P"                                                                       */
/*                                                                            */
/* Programa:	Incorporaciones                                               */
/* Descripción:	Nuevas incorporaciones de LPS                                 */
/* Fecha:		7 - May - 2022                                                */
/* ************************************************************************** */

#ifndef INCOR_H
# define INCOR_H

/*
** Libraries
*/
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
** Structure
*/
typedef struct	s_main
{
	char		*line;
	char		**nombre;
	char		*cargo;
	char		*email;
	char		*email_pass;
	char		*file_name;
	int			file_fd;
}				t_main;

/*
** Funtions
*/
void		*ft_calloc(size_t num, size_t size);
t_main		*fn_init_main(t_main *main);
char		**ft_split(char const *s, char c);
#endif
