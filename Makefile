CPP_FILES = `find . -name "*.cpp" -not -name "mainTest.cpp" -not -name "mainCheck.cpp" -not -name "main.cpp" -not -name "ClientMain.cpp"`
CPP_FILES1 = `find . -name "*.cpp" -not -name "mainTest.cpp" -not -name "mainCheck.cpp" -not -name "main.cpp" -not -name "ServerMain.cpp"`

all: server.out client.out

server.out:
	g++ -pthread -std=c++11 $(CPP_FILES) -o server.out

client.out:
	g++ -pthread -std=c++11 $(CPP_FILES1) -o client.out

clean:
	rm -f *.o server.out
	rm -f *.o client.out