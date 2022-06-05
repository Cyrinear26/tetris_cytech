all: exec


main.o: main.c affiche.h 
  gcc -c main.c -o main.o

affiche.o : affiche.c affiche.h
  gcc -c affiche.c -o affiche.o

exec: main.o affiche.o
  gcc affiche.o main.o -o exec   
