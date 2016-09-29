CC=gcc

main: main.o vchan_logging_interface.o sel4libvchan.o
	$(CC) $^ -o $@

clean:
	rm -f *.o main
