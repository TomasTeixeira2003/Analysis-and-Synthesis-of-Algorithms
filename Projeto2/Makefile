CC = g++
CFLAGS = -std=c++11 -O3 -Wall -lm -fsanitize=address 

make: p2_edge.cpp
	$(CC) $(CFLAGS) p2_edge.cpp -o p2_edge

run: p2_edge
	./p2_edge

test1: 
	./p2_edge < test1.txt

test2:
	./p2_edge < test2.txt

test3:
	./p2_edge < test3.txt

test4:
	./p2_edge < test4.txt

clean:
	rm -f 2_pair
