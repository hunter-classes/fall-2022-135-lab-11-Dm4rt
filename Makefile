main: main.o profile.o
	g++ -o main main.o profile.o
tests: tests.o profile.o
	g++ -o tests tests.o profile.o
main.o: main.cpp profile.h

tests.o:tests.cpp profile.h

profile.o: profile.cpp profile.h

clean:
	rm -f *o
