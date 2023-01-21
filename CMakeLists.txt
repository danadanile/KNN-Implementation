cmake_minimum_required(VERSION 3.24)
project(testEx4)

set(CMAKE_CXX_STANDARD 17)

add_executable(testEx4 ServerMain.cpp CheckFuncs.cpp DistanceType.cpp VectorMap.cpp Command.cpp Cli.cpp Data.cpp DefaultIO.h StandartIO.cpp UploadCommand.cpp VectorUnclassified.cpp SettingCommand.cpp DisplayCommand.cpp DownloadCommand.cpp ServerSocket.cpp SocketIO.cpp ClassifyCommand.cpp)

#add_executable(testEx4 ClientMain.cpp CheckFuncs.cpp DistanceType.cpp VectorMap.cpp Command.cpp Cli.cpp Data.cpp DefaultIO.h StandartIO.cpp UploadCommand.cpp VectorUnclassified.cpp SettingCommand.cpp DisplayCommand.cpp DownloadCommand.cpp ServerSocket.cpp SocketIO.cpp ClassifyCommand.cpp ClientSocket.cpp Client.cpp)