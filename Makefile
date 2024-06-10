STATIC_LIB	:= libft.a

CC		:= clang
CFLAGS		:= -std=c11 -Wall -Wextra -Iinclude -pedantic -MMD -MP -fPIC

AR		:= ar
SRC_DIR		:= src
OBJ_DIR		:= build
DEP_DIR		:= $(OBJ_DIR)
SRC_FILES	:= src/ctype.c src/string.c src/stdlib.c src/strings.c src/getopt.c src/math.c src/stdio.c src/ft.c
OBJ_FILES	:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES	:= $(patsubst %.c,$(DEP_DIR)/%.d,$(SRC_FILES))

ifndef san
	san := addr
endif

ifeq ($(san), addr)
	CFLAGS += -fsanitize=address,undefined
else ifeq ($(san), mem)
	CFLAGS += -fsantizie=memory,undefined -fsanitize-memory-track-origins
else ifneq ($(san), none)
$(error "$(san): invalid sanitizer")
endif

ifndef config
	config	:= distr
endif

ifeq ($(config), debug)
	CFLAGS += -g3 -fno-inline
else ifeq ($(config), release)
	CFLAGS +=  -g -O1
else ifeq ($(config), distr)
	CFLAGS += -g0 -O3
else
$(error "$(config): invalid config")
endif

all: $(STATIC_LIB)

bonus: all

$(STATIC_LIB): $(OBJ_FILES)
	rm -f $@
	ar rcs $@ $(OBJ_FILES)

$(OBJ_DIR)/%.o: %.c Makefile
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

check: all
	${MAKE} -B -C tests -kj

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)
fclean:
	${MAKE} clean
	rm -f $(STATIC_LIB)

fmt:
	clang-format -i $(SRC_FILES)

re:
	${MAKE} fclean
	${MAKE}

-include $(DEP_FILES)
.PHONY: all bonus clean fclean re
