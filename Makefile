# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:49:04 by anabaoui          #+#    #+#              #
#    Updated: 2019/05/11 17:18:08 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc -Wall -Wextra -Werror -I /usr/local/include src/*.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)

clean :
	@make clean -C libft

fclean :
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all
