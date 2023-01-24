CPP_FILES = $(wildcard *.cpp)
CPP_FILES := $(filter-out ClientMain.cpp, $(CPP_FILES))
CPP_FILES1 = $(wildcard *.cpp)
CPP_FILES1 := $(filter-out ServerMain.cpp, $(CPP_FILES1))

all: server.out client.out

server.out: $(CPP_FILES)
	g++ -pthread -std=c++11 $(CPP_FILES) -o server.out

client.out: $(CPP_FILES1)
	g++ -pthread -std=c++11 $(CPP_FILES1) -o client.out

clean:
	rm -f *.o server.out
	rm -f *.o client.out
