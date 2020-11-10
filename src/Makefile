FLAGS= -g -Wall

all: pattern_search

pattern_search: main.o pattern_search.o
	g++ $(FLAGS) -o pattern_search main.o pattern_search.o

main.o: main.cc
	g++ $(FLAGS) -c main.cc
	
pattern_search.o: pattern_search.cc
	g++ $(FLAGS) -c pattern_search.cc
	
clean:
	rm pattern_search main.o pattern_search.o
