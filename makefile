CC=gcc
SRC=src
ODIR=obj
BUILD_DIR=build
EXEC_NAME=gato
OPTIONS=-Wall

all: clean createdirs $(ODIR)/funciones.o
	$(CC) $(ODIR)/funciones.o $(SRC)/main.c $(OPTIONS) -o $(BUILD_DIR)/$(EXEC_NAME)

createdirs:
	mkdir -p $(ODIR)
	mkdir -p $(BUILD_DIR)

$(ODIR)/funciones.o: $(SRC)/funciones.c $(SRC)/funciones.h $(SRC)/structuras.h
	$(CC) $(SRC)/funciones.c $(OPTIONS) -c -o $(ODIR)/funciones.o

clean:
	rm -rf $(ODIR)/*
	rd -rf $(BUILD_DIR)/(EXEC_NAME)