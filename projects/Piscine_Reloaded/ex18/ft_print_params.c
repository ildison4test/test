/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:23:45 by cormund           #+#    #+#             */
/*   Updated: 2019/04/04 15:03:28 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int i;
	int j;

	if (ac > 1)
	{
		j = 1;
		i = 0;
		while (j < ac)
		{
			if (av[j][i] != '\0')
			{
				ft_putchar(av[j][i]);
				i++;
			}
			else
			{
				j++;
				i = 0;
				ft_putchar('\n');
			}
		}
	}
	return (0);
}
