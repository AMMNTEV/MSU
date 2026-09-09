CC = gcc
CFLAGS = -c

all: my_prog
	./my_prog
	
my_prog: func.o main.o autotest.o
	$(CC) func.o main.o autotest.o -o my_prog
	
func.o: func.c
	$(CC) $(CFLAGS) func.c
	
main.o: main.c
	$(CC) $(CFLAGS) main.c
autotest.o: autotest.c
	$(CC) $(CFLAGS) autotest.c

clean:
	rm -rf *.o my_prog
