[![HitCount](https://hits.dwyl.com/jianingxu1/practicaPRO2.svg?style=flat&show=unique)](http://hits.dwyl.com/jianingxu1/practicaPRO2)
[![GitHub stars](https://img.shields.io/github/stars/jianingxu1/practicaPRO2.svg)](https://github.com/jianingxu1/practicaPRO2/stargazers/)
[![GitHub forks](https://img.shields.io/github/forks/jianingxu1/practicaPRO2.svg)](https://github.com/jianingxu1/practicaPRO2/network/)
[![GitHub repo size in bytes](https://img.shields.io/github/repo-size/jianingxu1/practicaPRO2)](https://github.com/jianingxu1/practicaPRO2)
[![GitHub contributors](https://img.shields.io/github/contributors/jianingxu1/practicaPRO2.svg)](https://github.com/jianingxu1/practicaPRO2/graphs/contributors/)

# Circuito de torneos de tenis. Práctica de PRO2 (Primavera 2022).
## Información general
Este repositorio contiene el código con mi implementación de la práctica de PRO2 del curso 21-22Q2.
## Enunciado de la práctica
Esta práctica consiste en desarrollar un programa para manejar un circuito de tenis. 
El enunciado se puede leer en el documento [enunciat_practica_21-22Q2.pdf](https://github.com/jianingxu1/practicaPRO2/blob/main/enunciado_practica_21-22Q2.pdf) que proviene de la web oficial de la asignatura de [PRO2](https://www.cs.upc.edu/pro2/index.php?id=practica-primavera-2022).

Este programa contiene la implementación de comandos que permiten manejar un circuito de tenis que son:
1. `nuevo_jugador p`: lee y añade un nuevo jugador con identificador p (si éste es válido). El comando admite la forma abreviada `nj`. Si ya existe un jugador en el circuito con el mismo identificador, se imprime un mensaje de error. En caso contrario se añade el jugador con estadísticas a cero y última posición en el ranking y se imprime el número de jugadores P en el circuito después de añadirlo.
2. `nuevo_torneo t c`: lee un nuevo torneo con identificador t y categoría c y lo añade al circuito (si los datos son válidos). El comando admite la forma abreviada `nt`. Si la categoría c no está entre 1 y C se imprime un mensaje de error. Si lo está, pero ya existe un torneo en el circuito con el nombre t, se imprime otro mensaje de error. En caso contrario se imprime el número de torneos T en el circuito después de añadirlo.
3. `baja_jugador p`: da de baja en el circuito al jugador con identificador p. El comando admite la forma abreviada `bj`. Si no existe un jugador con identificador p se imprime un mensaje de error. En caso contrario se actualiza el ranking (desplazando una posición hacia arriba los jugadores siguientes en el ranking) y se imprime el número de jugadores P en el circuito después de darlo de baja. Si más tarde se añade otro jugador con el mismo nombre, es como si el anterior no hubiera existido.
4. `baja_torneo t`: da de baja en el circuito al torneo con identificador t. El comando admite la forma abreviada `bt`. Si no existe un torneo con identificador t se imprime un mensaje de error. En caso contrario, se actualiza el ranking después de restar los puntos conseguidos por los jugadores en la última edición del torneo (si se hubiera jugado alguna) y se imprime el número de torneos T en el circuito después de darlo de baja. Si más tarde se añade otro torneo con el mismo nombre, es como si el anterior no hubiera existido.
5. `iniciar_torneo t`: se lee la inscripción en el torneot y se confecciona e imprime el cuadro de emparejamientos de los jugadores inscritos. Se garantiza que el torneo t existe en el circuito. El comando admite la forma abreviada `it`. Primero se lee el número n de jugadores inscritos y luego se leen n enteros con sus posiciones en el ranking actual ordenadas crecientemente. El formato de escritura del cuadro de emparejamientos se deducirá del juego de pruebas público.
6. `finalizar_torneo t`: se leen los resultados del torneo t, se produce e imprime el cuadro oficial de resultados, y se listan los puntos para el ranking ganados por cada uno de los participantes; también se actualiza el ranking y las estadísticas de los jugadores. Se garantiza que el torneo t existe en el circuito y que previamente se ha ejecutado el comando iniciar_torneo t correspondiente. El comando admite la forma abreviada `ft`. Los resultados del torneo se leen como un árbol binario de strings en preorden siguiendo la estructura del cuadro de emparejamientos. El formato de escritura del cuadro de resultados se deducirá del juego de pruebas público. La lista de jugadores y puntos ganados por cada uno se escribe por orden de ranking de los jugadores en el momento de iniciar el torneo. La actualización del ranking ha de tener en cuenta, además de los puntos ganados en la presente edición que se suman, los puntos ganados en la edición anterior del torneo, si la hubiera, que se restan.
7. `listar_ranking`: se listan, por orden creciente de ranking actual, la posición, el nombre y los puntos de cada jugador del circuito. El comando admite la forma abreviada `lr`.
8. `listar_jugadores`: se listan, por orden creciente de identificador (nombre), el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del circuito. El comando admite la forma abreviada `lj`.
9. `consultar_jugador p`: lo mismo que la anterior, pero solamente para el jugador con identificador p. Si no existe un jugador con identificador p se imprime un mensaje de error. El comando admite la forma abreviada `cj`.
10. `listar_torneos`: se listan, por orden creciente de identificador (nombre), el nombre y la categoría de cada torneo del circuito. El comando admite la forma abreviada `lt`.
11. `listar_categorias`: se listan, por orden creciente de identificador, el nombre y la tabla de puntos por niveles (en orden creciente de nivel) de cada categoría del circuito. El comando admite la forma abreviada `lc`.
12. `fin`: termina la ejecución del programa.

## Ejecución del programa
**Requisitos:**
- Make. Para instalarlo, ejecutar en la terminal el comando:
```
  sudo apt install make
```
- g++. Para instalarlo, ejecutar en la terminal el comando:
```
  sudo apt install g++
```

**Ejecución:**
1. Navegar desde la terminal a la carpeta [src](https://github.com/jianingxu1/practicaPRO2/tree/main/src).
2. La carpeta [src](https://github.com/jianingxu1/practicaPRO2/tree/main/src) contiene todo el código fuente del programa y un fichero `Makefile`, que al ejecutarse, compilará y creará un ejecutable del programa. Para ejecutar el `Makefile`, escribir el comando:
```
  make Makefile
```
3. Para ejecutar el programa con un fichero como input, se puede utilizar el comando:
```
  ./program.exe <fichero_input
```
   Si se quiere probar el programa, se puede utilizar como input el fichero `sample.inp` de la carpeta [sample_completa](https://github.com/jianingxu1/practicaPRO2/tree/main/samples/sample_completa) con el comando:
```
  ./program.exe <../samples/sample_completa/sample.inp
```
   Como comprobación del correcto funcionamiento del programa, el output que se produce debería coincidir con el fichero `sample.out` de la carpeta [sample_completa](https://github.com/jianingxu1/practicaPRO2/tree/main/samples/sample_completa).

## Documentación
La documentación del programa se genera automáticamente utilizando el programa Doxygen y Graphviz. Se pueden instalar ejecutando los siguientes comandos en la terminal:
```
sudo apt install doxygen
sudo apt install graphviz
```
**Creación de la documentación:**
1. Navegar desde la terminal a la carpeta [src](https://github.com/jianingxu1/practicaPRO2/tree/main/src).
2. La carpeta [src](https://github.com/jianingxu1/practicaPRO2/tree/main/src) contiene un fichero `Doxyfile` que al ejecutarlo, nos permitirá crear la documentación con Doxygen y Graphviz. Para ejecutar el fichero `Doxyfile`, utilizar el comando:
```
  doxygen Doxyfile
```
3. Para abrir la documentación, utilizar el comando:
```
  xdg-open DOC/html/index.html
```
