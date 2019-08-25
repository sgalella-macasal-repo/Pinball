CC          = gcc
LD          = gcc 
CFLAG       = -Wall -Iinclude
EXE		    = pinball

SRC_DIR     = ./src
BUILD_DIR   = ./build
BIN_DIR     = ./bin
INC_DIR     = ./include

SRC_LIST = $(wildcard $(SRC_DIR)/*.c)
OBJ_LIST = $(BUILD_DIR)/$(notdir $(SRC_LIST:.c=.o))

all: $(EXE)

compile: 
	$(CC) -c $(CFLAG) $(SRC_LIST) -o $(OBJ_LIST)

$(EXE): compile
	$(LD) $(OBJ_LIST) -o $(BIN_DIR)/$@

clean:
	rm -f $(BIN_DIR)/$(EXE) $(BUILD_DIR)/*.o