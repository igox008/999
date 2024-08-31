#include <libc.h>

int main() {
    int fd = open("Makefile", O_CREAT | O_TRUNC, 0644);
    (fd != -1) && (close(fd));
    FILE *file = fopen("Makefile", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    const char *config =
        "RESET=\\033[0m\n"
        "BOLD=\\033[1m\n"
        "RED=\\033[31m\n"
        "GREEN=\\033[32m\n"
        "YELLOW=\\033[33m\n"
        "BLUE=\\033[34m\n"
        "MAGENTA=\\033[35m\n"
        "CYAN=\\033[36m\n"
        "WHITE=\\033[37m\n"
        "ORANGE=\\033[38;5;208m\n"
        "\n"
        "BG_RED=\\033[41m\n"
        "BG_GREEN=\\033[42m\n"
        "BG_YELLOW=\\033[43m\n"
        "BG_BLUE=\\033[44m\n"
        "BG_MAGENTA=\\033[45m\n"
        "BG_CYAN=\\033[46m\n"
        "BG_WHITE=\\033[47m\n"
        "\n"
        "CC = cc\n"
        "CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g\n"
        "RM = rm -rf\n"
        "\n"
        "NAME =  #exec\n"
        "INCLUDES = \n"
        "SRC = \n"
        "OBJ = $(SRC:.c=.o)\n"
        "\n"
        "all : $(NAME)\n"
        "\n"
        "$(NAME) : $(OBJ) $(INCLUDES)\n"
        "\t@echo \"$(ORANGE)$(BOLD)building $@...$(RESET)\"\n"
        "\t@$(CC) $(CFLAGS) $(OBJ) -o $@\n"
        "\t@echo \"$(GREEN)$@ is ready to use$(RESET)\"\n"
        "\n"
        "%.o : %.c $(INCLUDES)\n"
        "\t@echo \"$(YELLOW)$(BOLD)compiling $<...$(RESET)\"\n"
        "\t@$(CC) $(CFLAGS) -c $< -o $@\n"
        "\n"
        "clean :\n"
        "\t@$(RM) $(OBJ)\n"
        "\n"
        "fclean : clean\n"
        "\t@$(RM) $(NAME)\n"
        "\n"
        "re : fclean all\n"
        "\n"
        "run : all clean\n"
        "\t@read -p \"Enter arguments: \" INPUT && \\\n"
        "\tARG=$$INPUT && \\\n"
        "\t./$(NAME) $$ARG || \\\n"
        "\techo \"$(RED)Error: wrong input$(RESET)\"\n"
        "\n"
        ".PHONY : clean";

    if (fwrite(config, sizeof(char), strlen(config), file) != strlen(config)) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    fclose(file);
    
    return 0;
}
