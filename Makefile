CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

.PHONY: test
# Links together files needed to create executable                                                                                                                                                          
ac: main.o edits.o correct.o
	$(CC) -o ac main.o edits.o correct.o 

ac.o: main.cpp edits.h correct.h
	$(CC) $(CFLAGS) -c main.cpp

test: test.o edits.o correct.o
	$(CC) -o test test.o edits.o correct.o
	./test < tests/test_a.txt
	./test < tests/test_apeple.txt
test.o: test.cpp edits.h correct.h
	$(CC) $(CFLAGS) -c test.cpp

# Compiles functions.c to create functions.o                                                                                                                                                                
# Note that we list functions.h here as a file that                                                                                                                                                         
# functions.c depends on, since functions.c #includes it                                                                                                                                                    
edits.o: edits.cpp edits.h correct.h
	$(CC) $(CFLAGS) -c edits.cpp

correct.o: correct.cpp edits.h correct.h
	$(CC) $(CFLAGS) -c correct.cpp

clean:
	rm -f *.o main 
