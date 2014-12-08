all : Test_String.out

Test_String.out : Test_String.cpp String.o
	g++ -g -Wall -o Test_String.out Test_String.cpp String.o

String.o : String.cpp String.h
	g++ -g -Wall -o String.o String.cpp -c

clean:
	rm*.o

mrproper: clean
	rm Test_String.out
