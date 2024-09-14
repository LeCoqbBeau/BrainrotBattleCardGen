NAME = CardGen

INCLUDES = inc/

RAYLIB = $(INCLUDES)libraylib.a

CPP_FLAGS = -I$(INCLUDES) -Wall -Werror -Wextra -std=c++98 $(RAYLIB)
CC = c++

SRC_DIR = src/
SRC_NAME =	main.cpp \
			userInput.cpp \
			CardGen.cpp

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CPP_FLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)

%.o:%.cpp
	@$(CC) $(CPP_FLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $<

$(NAME): $(OBJ)
	@c++ $(CPP_FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[1;32m Executable" $(NAME) "created"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all
