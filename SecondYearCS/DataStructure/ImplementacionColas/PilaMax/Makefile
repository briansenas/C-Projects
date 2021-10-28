SRC = src
INC = inc
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c

all: $(BIN)/usopilas_max
# *********************+ Compilacion de modulos ***************
$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o

$(OBJ)/Pila_max_Cola.o: $(SRC)/Pila_max_Cola.cpp $(INC)/Pila_max_Cola.h
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_Cola.cpp -o $(OBJ)/Pila_max_Cola.o

$(OBJ)/Pila_max_VD.o: $(SRC)/Pila_max_VD.cpp $(INC)/Pila_max_VD.h
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_VD.cpp -o $(OBJ)/Pila_max_VD.o

$(OBJ)/cola.o: $(SRC)/cola.cpp $(INC)/cola.h
	$(CXX) $(CPPFLAGS) $(SRC)/cola.cpp -o $(OBJ)/cola.o

# ******************* Limpieza *******************
clean:
	rm $(OBJ)/* $(LIB)/*

mrproper:
	rm $(BIN)/*