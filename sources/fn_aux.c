
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

void	*ft_bzero(void *bzero_string, unsigned int num_char)
{
	unsigned char	*temp_pointer;

	temp_pointer = (unsigned char *)bzero_string;
	while (num_char-- > 0)
		*temp_pointer++ = 0;
	return (bzero_string);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*trgt;

	trgt = malloc(num * size);
	if (!trgt)
		return (NULL);
	ft_bzero(trgt, (num * size));
	return (trgt);
}

t_main	*fn_init_main(t_main *main)
{
	main = ft_calloc(1, sizeof(t_main));
	return (main);
}

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (*str++ != 0)
		cnt++;
	return (cnt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			cnt;
	unsigned int	ft_len;

	cnt = 0;
	if (s == NULL)
		return (NULL);
	str = ft_calloc(sizeof(*s), (len + 1));
	if (!str)
		return (NULL);
	ft_len = (unsigned int)(ft_strlen(s));
	while (cnt < len && start < ft_len)
	{
		str[cnt] = s[cnt + start];
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}

static	int	count_word(char const *str, char chr)
{
	int		swtch;
	int		cnt;

	swtch = 0;
	cnt = 0;
	while (*str != 0)
	{
		if (swtch == 1 && *str == chr)
			swtch = 0;
		if (swtch == 0 && *str != chr)
		{
			swtch = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

int	cnt_pnt_yes(int *cnt_pnt, const char *s, char c)
{
	int	cnt_tmp;

	cnt_tmp = *cnt_pnt;
	while (s[cnt_tmp] == c && s[cnt_tmp] != 0)
		cnt_tmp++;
	return (cnt_tmp);
}

int	cnt_pnt_no(int *cnt_pnt, const char *s, char c)
{
	int	cnt_tmp;

	cnt_tmp = *cnt_pnt;
	while (s[cnt_tmp] != c && s[cnt_tmp] != 0)
		cnt_tmp++;
	return (cnt_tmp);
}

char	**ft_split(char const *s, char c)
{
	int		split_num;
	char	**split_array;
	int		start;
	int		cnt_pnt;
	int		cnt_array;

	cnt_pnt = 0;
	cnt_array = -1;
	if (!s || !c)
		return (NULL);
	split_num = count_word(s, c);
	split_array = (char **)ft_calloc(sizeof(char *), split_num + 1);
	if (!split_array)
		return (NULL);
	while (++cnt_array < split_num)
	{
		cnt_pnt = cnt_pnt_yes(&cnt_pnt, s, c);
		start = cnt_pnt;
		cnt_pnt = cnt_pnt_no(&cnt_pnt, s, c);
		split_array[cnt_array] = ft_substr(s, start, cnt_pnt - start);
		cnt_pnt++;
	}
	split_array[cnt_array] = 0;
	return (split_array);
}
