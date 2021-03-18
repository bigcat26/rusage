
all: rusage test

.PHONY: clean

test: test.c
	gcc -Os -o $@ $^

rusage: rusage.c
	gcc -Os -o $@ $^

clean:
	rm -f rusage test