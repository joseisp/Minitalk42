# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 04:01:29 by jinacio-          #+#    #+#              #
#    Updated: 2022/01/14 19:27:05 by jinacio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILESERVER = server.c

FILECLIENT = client.c

CFLAGS = -Wall -Wextra -Werror

NAMESERVER = server

NAMECLIENT = client

UTILS = utils.c utils2.c 

all: $(NAMESERVER) $(NAMECLIENT)

$(NAMESERVER): $(FILESERVER)
	gcc $(CFLAGS) $(FILESERVER) -o $(NAMESERVER)

$(NAMECLIENT): $(FILECLIENT)
	gcc $(CFLAGS) $(FILECLIENT) $(UTILS) -o $(NAMECLIENT)

clean:
	rm $(NAMESERVER) $(NAMECLIENT)

fclean: clean

re: clean all