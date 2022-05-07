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

#include "../includes/incor.h"
#include <string.h>

char	**read_line(t_main *main, char splt)
{
	char	**ret_split;
	main->line = readline("\033[36mNombre:\\> \033[m");
	ret_split = ft_split(main->line, splt);
	return (ret_split);
}

char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result) // thanks @pmg
    {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

void	open_file(t_main *main)
{
	main->file_name = join("/Users/juancarlossantos/Desktop/", main->nombre[0]);
	main->file_name = join(main->file_name, "_");
	main->file_name = join(main->file_name, main->nombre[1]);
	main->file_name = join(main->file_name, ".txt");
	main->file_fd = open(main->file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	printf("FD: %i\n", main->file_fd);
}

void	write_file(t_main *main)
{
	int		n_bits;

	n_bits = strlen("Cuenta");
	printf("FD-1: %i\n", main->file_fd);
	write(main->file_fd, "Cuenta", n_bits);
	close(main->file_fd);


}

int		main()
{
	t_main	*main;
	int		cnt;

	cnt = -1;
	main = NULL;
	main = fn_init_main(main);
	main->nombre = read_line(main, ' ');
	main->cargo = readline("\033[36mCargo:\\> \033[m");
	main->email = readline("\033[36meMail:\\> \033[m");
	main->email_pass = readline("\033[36mPass_eMail:\\> \033[m");
	open_file(main);
	write_file(main);
	while(main->nombre[++cnt] != NULL)
		printf("Nombre: %s\n", main->nombre[cnt]);
	return (0);
}
