all:
	gcc -g -c -Wall main.c -o main.o
	gcc -g -c -Wall MetodoSimplex.c -o MetodoSimplex.o
	gcc -g -Wall main.o MetodoSimplex.o -o Simplex
clean:
	del *.o
	
remove:
	del Simplex.exe

	## instrucciones de ejecucion

	##poner en la terminal 
	##para compilar solo debes de escribir mingw32-make
	##para ejecutar los demas comandos debes de escribir esto + el comando