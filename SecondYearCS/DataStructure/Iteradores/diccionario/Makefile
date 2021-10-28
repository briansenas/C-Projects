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

$(OBJ)/ejecutable.o: $(SRC)/usoDiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/testdiccionario.cpp -o $(OBJ)/ejecutable.o

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o
# ******************* Limpieza *******************
clean:
	rm $(OBJ)/* $(LIB)/*

mrproper:
	rm $(BIN)/*