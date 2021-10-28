SRC = src
INC = inc
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c -std=c++11

all: $(BIN)/ejecutable
# *********************+ Compilacion de modulos ***************
$(BIN)/ejecutable: $(OBJ)/ejecutable.o
	$(CXX) -o $(BIN)/ejecutable $(OBJ)/ejecutable.o

$(OBJ)/ejecutable.o: $(SRC)/testguia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testguia.cpp -o $(OBJ)/ejecutable.o
# ******************* Limpieza *******************
clean:
	rm $(OBJ)/* $(LIB)/*

mrproper:
	rm $(BIN)/*
