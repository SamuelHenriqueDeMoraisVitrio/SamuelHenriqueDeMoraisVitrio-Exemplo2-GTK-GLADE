COMP = gcc
OPC = -Wall -std=c99
GTK = `pkg-config --cflags --libs gtk+-3.0`
NOME = EXE
START = echo "" && echo "Compilação concluida. Iniciando..." && echo "" && echo "" && ./$(NOME)

nome: clear
	$(COMP) $(OPC) -o $(NOME) *.c $(GTK) -rdynamic
	@$(START)

compile: clear
	$(COMP) $(OPC) -o $(NOME) *.c $(GTK) -rdynamic

clear:
	rm -f EXE .IU.glade.swp .main.c.swp
	clear

start:
	@$(START)
