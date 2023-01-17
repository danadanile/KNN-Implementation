cmake_minimum_required(VERSION 3.24)
project(testEx4)

set(CMAKE_CXX_STANDARD 17)

add_executable(testEx4 main.cpp VectorUnclassified.cpp VectorMap.cpp DistanceType.cpp CheckFuncs.cpp
        StandartIO.cpp DefaultIO.h Cli.cpp Data.cpp UploadCommand.cpp Command.cpp SettingCommand.cpp ClassifyCommand.cpp)
