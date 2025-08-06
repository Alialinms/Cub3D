/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:53:57 by alhamdan          #+#    #+#             */
/*   Updated: 2024/08/29 13:54:01 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	void			*pa;
	size_t			i;

	i = 0;
	pa = malloc(count * size);
	if (pa == NULL)
		return (NULL);
	p = pa;
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
/*int main() {
    int *arr;
    int num_elements = 5;
    
    // Allocating memory for an array of 5 integers
    arr = (int *)ft_calloc(num_elements, sizeof(int));
    
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return error code
    }
    
    // Printing the allocated array (should be initialized to zero)
    printf("Allocated array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Modifying the elements of the array
    for (int i = 0; i < num_elements; i++) {
        arr[i] = i + 1;
    }
    
    // Printing the modified array
    printf("Modified array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Freeing the allocated memory
    free(arr);
    
    return 0; // Return success code
}*/
