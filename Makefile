CXX= g++
CXXFLAGS= -std=c++2a
FLAGS= -Wall -g

all: do
	
do: main.o Document.o Editor.o
	$(CXX) $(CXXFLAGS) -o do main.o Document.o Editor.o
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
Document.o: Document.cpp Document.h
	$(CXX) $(CXXFLAGS) -c Document.cpp
Editor.o: Editor.cpp Editor.h
	$(CXX) $(CXXFLAGS) -c Editor.cpp

.PHONY: clean all do
	
clean:
	rm -f *.o all do
