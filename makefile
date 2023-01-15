# make: server.out client.out
# server.out:
# 	g++ -o server.out ServerMain.cpp Server.cpp Server.h CheckFuncs.cpp CheckFuncs.h DistanceType.cpp VectorMap.cpp DistanceType.h VectorMap.h -std=c++11

# client.out:
# 	g++ -o client.out ClientMain.cpp Client.cpp Client.h CheckFuncs.cpp CheckFuncs.h DistanceType.cpp DistanceType.h -std=c++11
# clean:
# 	rm -f *.o server.out
# 	rm -f *.o client.out


test2.out:
	g++ -std=c++11 `find . -name "*.cpp" -not -name "ServerMain.cpp" -not -name "ClientMain.cpp"` -o test.out

test.out:
	g++ -o server.out mainTest.cpp CheckFuncs.cpp DistanceType.cpp VectorMap.cpp Command.cpp Cli.cpp Data.cpp DefaultIO.h StandartIO.cpp UploadCommand.cpp VectorUnclassified.cpp -std=c++11

clean:
	rm -f *.o test.out
