# KNN Classifier Server
This repository provides program with server and client sides. The program implements KNN (k nearest neighbors) algorithm.
We classify vectors by finding theirs k nearest neighbors, the k vectors with the nearest distance.

## working with the program:
We enter server by giving port number.
We enter client by giving port and ip number.
When client connects to server he gets a menu. Client can choose between 5 1-5 and 8 options.
In number 1 option: client provides two files. First file is the file with which you want to classify the vectors and the second file is the file with vectors we want to classify.
In number 2 option: client can change the k parameter and the distance matric (distance algorithm for calculating the nearest k neighbors).
In number 3 option: client can classify his data.
In number 4 option: client can get output of his classification results to screen.
In number 5 option: client can download output of his classification results into a file.
In number 8 option: client can exit the system.

Note: there is a flow of choosing options. For example, client can classify data without making option 1 first.

## Compiling and Run Program:
To compile: First, in the terminal, enter a folder path to which you want to clone the files.
Then write the next commant:
```
git clone https://github.com/danadanile/advance1Ex4.git
```
Now, in the terminal make sure that you on the right path (where the files located).
write the next command: 
```
make
```
First, run the server.
Write the next command with your arrguments:
```
server.out file port
```
Then, run a client (on different terminal or computer)
Write the next command with your arrguments:
```
client.out ip port
```
(you can remove the out files by write "make clean")

Now, client can use program.

## Implementation:

### Server Side:
We use a [command design pattern](https://en.wikipedia.org/wiki/Command_pattern).
We have Command abstract class and five diferent commands that inherits this class, one command to each menu option.
Each command can be run by the server with execute() function that cn be run by server.
![image](https://user-images.githubusercontent.com/117977429/213930358-6a94df78-e4f0-4006-8185-8922dd63e603.png).

We have Cli class. It responsibble of running the different commands. We create vector with all the commands and run each command by execute().
Cli use DefultIo class member that responsible for I/O.
![image](https://user-images.githubusercontent.com/117977429/213931338-ec63d6c6-9c9e-4d3d-ac57-377bd40ced47.png).












