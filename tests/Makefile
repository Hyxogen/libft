SRC_DIR		:= .
OBJ_DIR		:= build
DEP_DIR		:= $(OBJ_DIR)

SRC_FILES	:= $(shell find . -type f -name '*.c')
DRIVER_FILES	:= $(patsubst %.c,$(OBJ_DIR)/%.out,$(SRC_FILES))
DEP_FILES	:= $(patsubst %.c,$(DEP_DIR)/%.d,$(SRC_FILES))

CFLAGS		:= -I../include -MMD -MP -g3 -fsanitize=address,undefined

all: $(DRIVER_FILES)

$(OBJ_DIR)/%.out: $(SRC_DIR)/%.c Makefile ../libft.a
	mkdir -p $(@D)
	$(CC) -o $@ $< $(CFLAGS) ../libft.a
	./$@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

.PRECIOUS: $(DRIVER_FILES)
.PHONY: all clean
