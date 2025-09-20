/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:06:37 by jkubaev           #+#    #+#             */
/*   Updated: 2025/09/11 15:08:51 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char const **argv, char **envp)
{
	int i = 0;
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
	return 0;
}
