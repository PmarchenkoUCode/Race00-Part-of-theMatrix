NAME	=	part_of_the_matrix
CMPL	=	gcc
FLGS	=	-Wall -Wextra -Werror
DIRF	=	./src/
DIRO	=	./obj/
INCL	=	./inc/
INCD	=	$(addprefix -I, $(INCL))
OBJS	=	$(FUNC:.c=.o)
OBJC	=	$(addprefix $(DIRO), $(OBJS))
FUNC	=	mx_atoi.c mx_isdigit.c mx_isspace.c mx_matrix.c mx_printchar.c \
			mx_printint.c mx_printstr.c mx_spaceout.c mx_strndup.c mx_strcpy.c\
			mx_strlen.c mx_strnew.c mx_operation.c mx_print_unicode.c mx_pow.c\
			mx_print_bits.c


all: $(NAME)

$(NAME): $(OBJC)
	@$(CMPL) -o $(NAME) $(OBJC)
	@echo "\x1B[0;32m$(NAME) ready\x1B[0m"

$(DIRO)%.o: $(DIRF)%.c
	@mkdir -p $(DIRO)
	@$(CMPL) $(FLGS) $(INCD) -o $@ -c $<

clean:
	@rm -rf $(DIRO)
	@echo "\x1B[1;31mobjects $(NAME) deleted\x1B[0m"

fclean:	
	@rm -rf $(DIRO)
	@echo "\x1B[1;31mobjects $(NAME) deleted\x1B[0m"
	@rm -f $(NAME)
	@echo "\x1B[0;31m$(NAME) deleted\x1B[0m"

re: fclean all
