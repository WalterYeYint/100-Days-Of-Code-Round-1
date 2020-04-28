#if any change, recompile and create exe
output: main.o message.o
		g++ main.o message.o -o output

#don't create exe but o file
main.o: main.cpp
		g++ -c main.cpp

#any change in .cpp  or .h and run this
message.o: message.cpp message.h
		g++ -c message.cpp

clean:
		rm *.o output