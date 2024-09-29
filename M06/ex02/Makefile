# Compilation Flags
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
NAME = Base
SRCS = $(wildcard *.cpp)
DEPS = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)

# Compilation
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into executable
$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

# Standard rules
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re