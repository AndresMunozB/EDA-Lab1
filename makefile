CC=gcc
SRC=src
ODIR=obj
BUILD_DIR=build
EXEC_NAME=programa.exe
OPTIONS=-Wall

all: clean createdirs 
	$(CC)  $(SRC)/main.c $(SRC)/funciones.c $(OPTIONS) -o $(BUILD_DIR)/$(EXEC_NAME)

createdirs:
	mkdir $(ODIR)
	mkdir $(BUILD_DIR)



clean:
	rmdir $(ODIR) /S /Q
	rmdir $(BUILD_DIR) /S /Q	