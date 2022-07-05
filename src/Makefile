OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
G++ = g++

# Compila y linkea todos los archivos creando el ejecutable program.exe.
# Se ejecuta con el comando "make"
program.exe: program.o Cjt_jugadores.o Jugador.o Cjt_categorias.o Cjt_torneos.o Torneo.o
	g++ -o program.exe program.o Cjt_jugadores.o Jugador.o Cjt_categorias.o Cjt_torneos.o Torneo.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh
	g++ -c Cjt_jugadores.cc $(OPCIONS)

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)

Cjt_categorias.o: Cjt_categorias.cc Cjt_categorias.hh
	g++ -c Cjt_categorias.cc $(OPCIONS)

Cjt_torneos.o: Cjt_torneos.cc Cjt_torneos.hh
	g++ -c Cjt_torneos.cc $(OPCIONS)

Torneo.o: Torneo.cc Torneo.hh
	g++ -c Torneo.cc $(OPCIONS)

# Se ejecuta con el comando "make practica.tar"
practica.tar:
	tar -cvf practica.tar *.cc *.hh Makefile html.zip

# Elimina todos los ficheros .o y .exe
# Se ejecuta con el comando "make clean"
clean:
	rm -f *.o
	rm -f *.exe
