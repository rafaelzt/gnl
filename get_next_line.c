/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:15:21 by rzamolo-          #+#    #+#             */
/*   Updated: 2023/02/02 17:35:20 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
INFO: char *get_next_line(int fd)
INFO: Static Variable concept
DONE: Open file
TODO: Read file or stdin (# of characters = BUFFER)
TODO: Look to '\n' until '\0'
TODO:   If '\n' -> print all text until new line, store rest in a variable
TODO:   If not '\n' -> still reading (# of characters = BUFFER) \
				store in a variable both, old read content and new read content
*/

#include <unistd.h> // write & read
#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <fcntl.h> // open

#ifndef BUFFERSIZE
	#define BUFFERSIZE 1
#endif

char *read_file(int file_descriptor)
{
	int fd;
	int size;
	char *c;

	c = (char *)calloc((BUFFERSIZE + 1), sizeof(char));
	if (!c)
		return (NULL);
	fd = file_descriptor;
	size = read(fd, c, BUFFERSIZE);

	return (c);
}

char *get_next_line(int fd)
{
	(void)fd;
	char	*ptr;

	ptr = NULL;
	return (ptr);
}

int open_file(char *filename)
{
	int file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		write(1, "Failed to open file!\n", 17);
	return (file_descriptor);
}

int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	int	index;

	index = 1;
	if (ac == 1)
		read_file(1);
	else
		while (ac > index)
		{
			get_next_line(open_file(av[index++]));
		}
	return (0);
}
