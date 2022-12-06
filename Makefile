main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o
tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o
main.o: main.cpp profile.h network.h

tests.o:tests.cpp profile.h

network.o: network.cpp network.h profile.h

profile.o: profile.cpp profile.h

clean:
	rm -f *o
