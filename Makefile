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
DIR_ENT1  := ./ConjuntodeTeste1/teste100_1/
DIR_ENT2  := ./ConjuntodeTeste2/teste100_2/
DIR_ENT3  := ./ConjuntodeTeste1/teste30_1/
DIR_ENT4  := ./ConjuntodeTeste2/teste10_2/
DIR_ENT5  := ./ConjuntodeTeste2/teste50_2/
DIR_ENT6  := ./input/T_P500_S25_W500/
DIR_ENT7  := ./input/T_P1000_S35_W1500/
DIR_ENT8  := ./input/T_P5000_S25_W700/

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	@-$(RM) $(OBJECTS)

# Comandos para executar
run: 
	# ./$(EXECUTABLE) $(DIR_ENT0) ./output/
	echo "run0"

# Comandos de testes utilizados
run0: 
	@./$(EXECUTABLE) $(DIR_ENT0) 

run1:
	@./$(EXECUTABLE) $(DIR_ENT1)

run2:
	@./$(EXECUTABLE) $(DIR_ENT2)

run3:
	@./$(EXECUTABLE) $(DIR_ENT3)

run4:
	@./$(EXECUTABLE) $(DIR_ENT4)

run5:
	@./$(EXECUTABLE) $(DIR_ENT5)
	
run6:
	@./$(EXECUTABLE) $(DIR_ENT6)

run7:
	@./$(EXECUTABLE) $(DIR_ENT7)

run8:
	@./$(EXECUTABLE) $(DIR_ENT8)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES) -lm

# Comandos para executar com valgrind
val: 
	# valgrind ./$(EXECUTABLE) $(DIR_ENT0) $(SAIDA)
	echo "val0"

# Comandos de testes utilizados
val0: 
	@valgrind --leak-check=full ./$(EXECUTABLE) $(DIR_ENT0)

val1:
	@valgrind --tool=massif ./$(EXECUTABLE) $(DIR_ENT1) 

val2:
	@valgrind --tool=massif ./$(EXECUTABLE) $(DIR_ENT2)

val3:
	@valgrind --leak-check=full ./$(EXECUTABLE) $(DIR_ENT3)

val4:
	@valgrind --leak-check=full ./$(EXECUTABLE) $(DIR_ENT4)

val5:
	@valgrind --leak-check=full ./$(EXECUTABLE) $(DIR_ENT5)

val6:
	@valgrind --tool=massif ./$(EXECUTABLE) $(DIR_ENT6)

val7:
	@valgrind ./$(EXECUTABLE) $(DIR_ENT7)

val8:
	@valgrind ./$(EXECUTABLE) $(DIR_ENT8)