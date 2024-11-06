#include "Bureaucrat.hpp"
C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS = -g -O0

NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

debug: $(OBJ)
	$(C) $(CFLAGS) $(DEBUG_FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
