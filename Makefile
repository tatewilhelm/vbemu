CC ?= gcc
CCFLAGS := -Wall -g
LINKER_FLAGS = -lSDL2

# path
BIN_PATH := bin
SRC_PATH := src

# compile
TARGET_NAME := vbemu 
TARGET := $(BIN_PATH)/$(TARGET_NAME)

SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
SRC += $(foreach x, include, $(wildcard $(addprefix $(x)/*,c.*)))
SRC += $(foreach x, $(SRC_PATH)/chip8, $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

all: $(TARGET)

$(TARGET): $(SRC)

	$(CC) $(CCFLAGS) -o $@ $(SRC) $(LINKER_FLAGS)
clean:
	rm $(TARGET)
