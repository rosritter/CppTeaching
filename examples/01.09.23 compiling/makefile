CC=g++
SHELL=/bin/bash
SRCS=$(wildcard src/*.cpp)
TESTS=$(wildcard tests/*.cpp)
OBJS=$(subst src/,build/,${SRCS:.cpp=.o})
TOBJS=$(subst tests/,build/,${TESTS:.cpp=.o})

all: app suite validate cppcheck

build/%.o: %.cpp| build
	$(CC) -c -Iheaders -o $@ $<

build/%.o: src/%.cpp | build
	$(CC) -c  -Iheaders -o $@ $<

build/%.o: tests/%.cpp| build
	$(CC) -c  -Iheaders -o $@ $<

app: ${OBJS} build/main.o
	$(CC) -o $@ ${OBJS} build/main.o

suite: ${TOBJS} ${OBJS} 
	$(CC) -o $@ ${TOBJS} ${OBJS}

validate:
	./suite

cppcheck:
	cppcheck --std=c++20 ${HDRS} ${SRCS} ${TESTS} 

build:
	mkdir build

clean:
	\rm -rf build
	
vars:
	echo "srcs=${SRCS}"
	echo "objs=${OBJS}"
	echo "tests=${TESTS}"
	echo "tobjs=${TOBJS}"