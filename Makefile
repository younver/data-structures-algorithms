CC = g++


all:
	echo "provide keyword"

stack:
	$(CC) structures/stack/test_stack.cpp -o stack.o

queue:
	$(CC) structures/queue/test_queue.cpp -o queue.o


clean:
	rm -rf *.o
