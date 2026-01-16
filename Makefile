# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_login <your_login@student.42.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/XX/XX XX:XX:XX by your_login       #+#    #+#              #
#    Updated: 2024/XX/XX XX:XX:XX by your_login      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRCS = ft_printf.c \
       ft_conversion.c \
       ft_putchar.c \
       ft_putstr.c \
       ft_putnbr.c \
       ft_putnbr_unsigned.c \
       ft_puthex_lower.c \
       ft_puthex_upper.c \
       ft_putptr.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = ft_printf.h

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)✓ Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)✓ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
```

## 📁 Structure du projet
```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_conversion.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putnbr.c
├── ft_putnbr_unsigned.c
├── ft_puthex_lower.c
├── ft_puthex_upper.c
├── ft_putptr.c
└── libft/
    ├── Makefile
    ├── libft.h
    ├── ft_*.c
    └── ...