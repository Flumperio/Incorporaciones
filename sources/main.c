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

int	ft_islower(int chr)
{
	return (chr >= 97 && chr <= 122);
}

int	ft_isupper(int chr)
{
	return (chr >= 65 && chr <= 90);
}

int	ft_tolower(int chr) {
	if (ft_isupper(chr) == 1)
		return (chr + 32);
	return (chr);
}

int	ft_toupper(int chr)
{
	if (ft_islower(chr) == 1)
		return (chr - 32);
	return (chr);
}

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

void	write_char(char *str1, const char *separator, t_main *main)
{
	int		n_bits;

	n_bits = 0;
	n_bits = (int)strlen(str1);
	write(main->file_fd, str1, n_bits);
	write(main->file_fd, separator, 1);
}

void	write_file(t_main *main)
{
	int		cnt;
	int 	tmp;

	cnt = -1;
	tmp = 0;
	write_char("CUENTAS\nNombre Completo (Correo):", "\n", main);
	while(main->nombre[++cnt] != 0)
		write_char(main->nombre[cnt], " ", main);
	write(main->file_fd, "\n", 1);
	write_char("Departamento:", "\n", main);
	write_char(main->cargo, "\n", main);
	write(main->file_fd, "\n", 1);
	write_char("Correo Electrónico", "\n", main);
	write_char("Usuario:", "\t", main);
	write_char(main->email, "@", main);
	write_char("lpsingenieria.com", "\n", main);
	write_char("Contraseña:", "\t", main);
	write_char(main->email_pass, "\n", main);
	write(main->file_fd, "\n", 1);
	write_char("VPN", "\n", main);
	write_char("Usuario:", "\t", main);
	tmp = ft_tolower(main->nombre[0][0]);
	main->nombre[1][0] = (char)ft_tolower(main->nombre[1][0]);
	write(main->file_fd, &tmp, 1);
	write(main->file_fd, main->nombre[1], (int)strlen(main->nombre[1]));
	write(main->file_fd, "\n", 1);
	write_char("Contraseña:", "\t", main);
	write(main->file_fd, "LPS", 3);
	write(main->file_fd, main->nombre[0], 1);
	write(main->file_fd, main->nombre[1], 3);
	write_char(".2022", "\n", main);
	write(main->file_fd, "\n", 1);
	write_char("Servidor", "\n", main);
	write_char("Usuario:", "\t", main);
	write_char(main->email, "@", main);
	write_char("LPS.local", "\n", main);
	tmp = ft_tolower(main->nombre[0][0]);
	write_char("Contraseña:", "\t", main);
	write(main->file_fd, "LPS", 3);
	write(main->file_fd, main->nombre[0], 1);
	write(main->file_fd, main->nombre[1], 3);
	write_char(".2022", "\n", main);
	write(main->file_fd, "\n", 1);
	write_char("Skype", "\n", main);
	write_char("Usuario:", "\t", main);
	write_char(main->email, "@", main);
	write_char("lpsingenieria.com", "\n", main);
	write_char("Contraseña:", "\t", main);
	write_char("LPS_ingenieria2022", "\n", main);
	write_char("Nombre:", "\t", main);
	write(main->file_fd, "\t", 1);
	write_char("LPS", "_", main);
	write_char(main->nombre[0], "_", main);
	main->nombre[1][0] = (char)ft_toupper(main->nombre[1][0]);
	write_char(main->nombre[1], "\n", main);
	write(main->file_fd, "\n", 1);
	write_char("Equipo", "\n", main);
	write_char("Usuario:", "\t", main);
	write_char(main->email, "\n", main);
	write_char("Contraseña:", "\t", main);
	write_char("LPS_ingenieria2022", "\n", main);
	write(main->file_fd, "\n", 1);
	write_char("Nombre de Equipo:", "\n", main);
	write_char("LPSXXX", "\n", main);
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
	main->email = readline("\033[36mCuenta_Servidor:\\> \033[m");
	main->email_pass = readline("\033[36mPass_eMail:\\> \033[m");
	open_file(main);
	write_file(main);
	while(main->nombre[++cnt] != NULL)
		printf("Nombre: %s\n", main->nombre[cnt]);
	return (0);
}
