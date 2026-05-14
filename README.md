# Battleship game

## The required file to execute this software

The tree structure of the project:
```
-- battleship
    |-- bin
        `-- *.o
        `- *.bin
    |-- src
        `- *.h
        `- *.cpp 
    |-- ws
        `-flotille.txt
        `-makefile
        `-deroulement.txt
        `-README.txt
    |-- README.md
```

The tree structure is necessary to run the project. Moreover, you must have the
flotille.txt's file. In this file, you will have to write the name of the boats
that you want on the board, the length of the boat and the number of boats of this
class/type like this:

```
Name_of_boat number_of_boat_of_this_type length_of_boat
```

When the line starts with a '#', the line is not taken into account, this is a comment line.

## Installation

To run the project, you've to be in the ws's directory:
```bash
cd ws
```
When you're in this directory, you can use the make file to easily launch the project.

#### Run the test

To run the three tests classes (testCGui, textCArmada, testCBateau), you can use the command bellow:
```bash
make testGCui
make testCArmada
make testCBateau
```

#### Run the game

To play, you can use this command:
```bash
make lanceurFinal
```
As mentioned higher, you must have set the flotille.txt's file. Next, it'll ask you to select a server and a client.
After that you will be able to play.
