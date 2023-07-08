/*
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Esad İsmail Tök
* ID: 21801679
* Section : 2
* Assignment : 4
* Description : Text (.txt) file that contains necessary informations about the compilation of the homework 4
*/

Used Files and Classes:
- Word.h, Word.cpp -> Includes the "Word" class for the Word Network.
- LinkedList.h, LinkedList.cpp -> Includes the "LinkedList" class that is used for the seperate chaining in the Hash Table.
- HashTable.h, HashTable.cpp -> Includes the "HashTable" class that uses seperate chaining.
- Stack.h, Stack.cpp -> Includes the "Stack" class that is used for the DFT operations in the Word Network.
- Queue.h, Queue.cpp -> Includes the "Queue" class that is used for the BFT operations in the Word Network.
- WordNetwork.h, WordNetwork.cpp -> Includes the "WordNetwork" class that performs the operations that is required for the homework.


Notes About Compilation:
- All of the ".cpp" files need to be compiled together with a main.cpp file to create the executable.
- There is nothing unusual in the compilation of the homework.
- The Code is tested in both Windows machine and Dijkstra server and it works properly.


Notes about the methods in the WordNetwork class:
- After creating an object of the WordNetwork class providing a vertex and edge file in a main.cpp file, the public functions 
that are described in the homework description can be used as normal.
- The vertex and edge files provided in the homework manual had an empty line at the end of the each file therefore an if block is added in the constuctor
to prevent the read of the empty lines.

