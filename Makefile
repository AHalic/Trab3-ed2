# Grupo: 
# Beatriz Maia: 2019107651
# Ryan Monteiro: 2019202359
# Sophie Dilhon: 2019107591
# Victor Aguiar Marques: 2018206897

CC		:= gcc
CFLAGS	:= 

BIN		:= bin
SRC		:= src
INCLUDE	:= src

EXECUTABLE	:= trab3
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

# Argumentos utilizados para testar codigo

# Caso teste do pdf
DIR_ENT0  := ./input/input0/
 
CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(OBJECTS)

# Comandos para executar
run: 
	# ./$(EXECUTABLE) $(DIR_ENT0) ./output/
	echo "run0"

run0: 
	./$(EXECUTABLE) $(DIR_ENT0) 
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES)

# Comandos para executar com valgrind
val: 
	# valgrind ./$(EXECUTABLE) $(DIR_ENT0) $(SAIDA)
	echo "val0"

val0: 
	valgrind ./$(EXECUTABLE) $(DIR_ENT0)