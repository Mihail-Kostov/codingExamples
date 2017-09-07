#makefile for gallery c++ programs.
#Note, being all-incllusive here: you can cut out libraries/includes you do not need
#you can also change the flags if you want too (Werror, pedantic, etc.)

CXXFLAGS=-std=c++14 #-Wall #-pedantic #-Werror
CXX=g++

all: main

main: main.cxx DecayVertex.cxx
	@$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o main