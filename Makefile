all: generator program
generator: generator.o
	gcc generator.o -o generator
lab.o: generator.c
	gcc -c generator.c
program: program.o
	gcc program.o -o program
program.o: program.c
	gcc -c program.c
clean:
	rm -rf*.o
