Repository URL:
https://github.com/connormeredithcu/Meredith_CSCI2270_FinalProject

Project Summary:
My final project is a chatterbot/text mimicker. The goal of this project is to make a program that can be given text inputs
and from these, create new yet grammatical outputs.
To do so, I have implemented a directed graph with edge weights. Each vertex of the graph represents a word that
has been entered to the program and each edge represents a pairing of words in a sentence. The weight on an edge between two words
represents the number of times that the word pair has been used. For example, an edge/vertex pair that looks like this:
Bob---1-->Runs
would mean that when the word "Bob" is used in a sentence, the word "Runs" has been used directly afterwards once.
To generate a sentence, the program randomly chooses a word that has been previously used (by the human) to
start a sentence and then randomly follows edges with heavier edges being liklier. For example, the user could enter
the two sentences "I am a dog." and "You are a cat." and the program's graph would look like this:
I     You
|1     |1
V      V
am    are
|      |
 +--+--+
    |1
    V
    a
    |
 +--+--+
 |.5   |.5
 V     V
dog   cat
Then, the program could create the sentence "You are a dog." despite the user never entering such a sentence!
A helper binary search  tree is included. At each node of the tree, a pointer to a vertex in the response graph is included. This
helps with traversal of the graph and allows for in order traversal of nodes based on alphabetization.
As the program is interacted with more and more, I hope that grammatical and novel sentences will become
liklier.
There is an option to load a file of sentences and to save a session of interactions with the user. Basically, this treats
each sentence as though the user had entered it. Similarly, when a session is saved, a text file of sentences separated into
individual lines is created.
The user can determine the structure of the graph by selecting one of the three traversal options.



How to run:
The program will repeatedly display a list of options as described below. To select an option, type the corresponding number and press enter.
1. Enter a sentence:
This option prompts the user for a sentence. Type a grammatical sentence and press enter after selecting this option.
The program takes this sentence, splits it up based on whitespace, and creates or modifies an edge in its response graph for
each word pair.
2. Read in sentences from a file.
This option prompts the user for the name of a file containing sentences separated by lines. Type a complete filename (with extension) and press
enter after selecting this option.
The program takes this filename and attempts to open the corresponding file. If it is successful, then it reads in data line by line and enters
each sentence as in option 1.
3. Have me say a sentence.
This option generates a pseudo-grammatical sentence. Simply select this option and a sentence will be displayed.
The program has been keeping track of "starting words" entered by the user and it randomly chooses one of these words. More frequent
words are chosen more frequently, as one might expect. From there, the program finds the proper vertex in the response graph, displays
its word key, and then chooses a random child with more frequently used children chosen more frequently. Then the process is repeated.
This continues until the program selects a vertex that has no children.
4. Have me say a bunch of sentences.
This option repeatedly performs option 3. Type a number (this is the number of sentences to be produced) and press enter after selecting this option.
5. Interact with me for a while.
This option repeatedly performs options 1 and 3. Type a number (this will be the number of times you enter a sentence and the number of times the
program produces a sentence) and press enter after selecting this option.
The point of this option is to create a conversation-like interaction between the program and user. It is much simpler to respond to the things
that the program randomly says than it is to generate your own sentences over and over again.
6. Display edges and vertices.
This option will display a 3 choice menu giving the options of an in-order, pre-order, and post-order display of vertices in the response graph. Before
you freak out, it DOES make sense to say something like this. A Binary Search Tree has been implemented and it contains pointers to vertices in the
response graph. Hence, words can be displayed in these orders.
Type a number corresponding to the order with which the vertices and edges should be displayed and press enter after selecting this option.
7. Exit program.
This option allows you to save and quit. If you do not wish to save, then type "2" and press enter after selecting this option. If you wish to save, then
type "1" and press enter after selecting this option. You will then be prompted to enter the name of a text file. Enter whatever name you'd like as long
as it contains no "forbidden" characters (e.g., '/') or whitespace. Do this and press enter. The program will then exit. (To recover this in a future
run of the program, use option 2)
The program has been keeping track of sentences entered by the user and will write them into the specified text file, line by line.

Dependencies:
This program uses standard c++ libraries. They are listed below:
iostream
vector
stdlib.h
sstream
fstream
I expect that no work needs to be done by the user to run this program.

System Requirements:
This program was written for Windows 8.1.

Contributors:
Connor Meredith

Open Issues/Bugs:
Currently, only filenames that have no whitespace are allowed. This could be fixed in the Utilities.cpp file.
Also, I have retroactively used the cin.ignore() function to fix my program skipping getline(cin, stringVar)
lines of code. Any advice would be welcome. The issues I was encountering mainly occured in the Utilities.cpp file.