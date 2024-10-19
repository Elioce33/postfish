# Flags pour le compilateur:
GTK_CFLAGS = $$(pkg-config --cflags gtk4)

# Flags pour l'editeur de liens:
GTK_LDFLAGS = $$(pkg-config --libs gtk4)


# path macros
BIN_PATH := bin
SRC_PATH := src


# compile macros
TARGET_NAME := make-a-choice
TARGET := $(BIN_PATH)/$(TARGET_NAME)
TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)

# clean files list
# DISTCLEAN_LIST := $(OBJ) \
#                   $(OBJ_DEBUG)
CLEAN_LIST := $(TARGET)
# 			  $(TARGET_DEBUG) \
# 			  $(DISTCLEAN_LIST)


default : makedir all


all: 
	gcc $(GTK_CFLAGS) -o $(TARGET) src/make-a-choice.c $(GTK_LDFLAGS)


makedir:
	@mkdir -p $(BIN_PATH)


clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm $(CLEAN_LIST)


# reference for this makefile : https://github.com/TheNetAdmin/Makefile-Templates/blob/master/SmallProject/Template/Makefile