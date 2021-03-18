
all: rusage

rusage: rusage.c
	gcc -Os -o rusage $^