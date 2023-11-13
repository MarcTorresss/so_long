/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:24 by martorre          #+#    #+#             */
/*   Updated: 2023/11/13 17:34:05 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft.h"

void    check_file(char *str)
{
    if(ft_strlen(ft_strnstr(str, ".bar", ft_strlen(str))) == ft_strlen(".bar"))
        ft_printf("OOOOOKKKKKKKK");
    else
        ft_printf("Invalid file!\n");
}
int	main(int argc, char **argv)
{
	/*int fd;
	char *new;
	int i;
	int	num;

	i = 0;*/
    //(void) argv;
    if  (argc > 2)
        ft_printf("To many arguments!\n");
    else
        check_file(argv[1]);
	/*fd = open("hola", O_RDONLY);
	new = get_next_line(fd);
	while (new != NULL)
	{
		write(1,new, ft_strlen(new));
		free(new);
		new = get_next_line(fd);
	}*/
	return (0);
}