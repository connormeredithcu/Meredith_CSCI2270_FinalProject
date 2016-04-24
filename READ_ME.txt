This is the read me file for my final project. It outlines the intended functionality of my program.

My final project will be a text mimicker. The goal of this project is to make a program that can be given text inputs
and from these, create new yet grammatical outputs.
To do so, I will implement a directed graph with edge weights. Each vertex of the graph will represent a word that
has been entered to the program and each edge will represent a pairing of words in a sentence. The weight will
represent the frequency that the word pair has been used. For example, an edge/vertex pair that looks like this:
Bob---1-->Runs
would mean that when the word "Bob" is used in a sentence, the word "Runs" is used afterwards 100% of the time.
To generate a sentence, the program will randomly choose a word that has been previously used (by the human) to
start a sentence and then randomly follow edges with heavier edges being liklier. For example, the user could enter
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
As the program is interacted with more and more, I hope that grammatical and novel sentences will become
liklier.
