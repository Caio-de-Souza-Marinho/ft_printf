/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:11:51 by caide-so          #+#    #+#             */
/*   Updated: 2024/11/20 20:40:28 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <limits.h>

#include <stdio.h>

typedef union
{
    unsigned long uint64;
    long int64;
} int_union;

int main() {
    int_union u;
    u.uint64 = 0xFFFFFFFFFFFFFFFF;

    printf("Unsigned: %lu\n", u.uint64); // Access as unsigned long
    printf("Signed: %ld\n", u.int64);   // Access as signed long (type punning)

    return 0;
}
