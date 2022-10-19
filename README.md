# Circuito de torneos de tenis. Práctica de PRO2 (Primavera 2022).
## Información general
Este repositorio contiene el código de la práctica de PRO2 del año 2021/2022 (Q2).
## Enunciado de la práctica
Se ha desarrollado un programa para manejar un circuito de tenis. 
El enunciado de la práctica se puede leer en el fichero [enunciat_practica_21-22Q2.pdf](https://github.com/jianingxu1/practicaPRO2/blob/main/enunciado_practica_21-22Q2.pdf) que proviene de la web oficial de la asignatura de [PRO2](https://www.cs.upc.edu/pro2/index.php?id=practica-primavera-2022).

Este programa contiene todos los comandos que permiten manejar un circuito de tenis. Se posibilita, por ejemplo:
- Manipular la cantidad de torneos y jugadores.
- Disputar torneos.
- Imprimir los torneos, las categorias, el ranking de jugadores y las estadísticas de un jugador.
- Etc.
  
Se realizan todas las operaciones actualizando debidamente los puntos, el ranking y/o las estadísticas de los jugadores que puedan implicar.

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
