STATIC_LIB	:= libft.a

CFLAGS		:= -std=c11 -Wall -Wextra -Iinclude -pedantic -MMD -MP

AR		:= ar
SRC_DIR		:= src
OBJ_DIR		:= build
DEP_DIR		:= $(OBJ_DIR)
SRC_FILES	:= src/ctype.c
OBJ_FILES	:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES	:= $(patsubst %.c,$(DEP_DIR)/%.d,$(SRC_FILES))

all: $(STATIC_LIB)

$(STATIC_LIB): $(OBJ_FILES)
	rm -f $@
	ar rcs $@ $<

$(OBJ_DIR)/%.o: %.c Makefile
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

check: all
	${MAKE} -C tests -kj

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
fclean:
	${MAKE} clean
	rm -f $(STATIC_LIB)

re:
	${MAKE} fclean
	${MAKE}

-include $(DEP_FILES)
.PHONY: all clean fclean re
