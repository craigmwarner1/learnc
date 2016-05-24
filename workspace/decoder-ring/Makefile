clean:
	rm -f run_tests

tests: clean
	gcc -o ring ring.c
	gcc -o run_tests ring.c tests.c 

all: clean tests
