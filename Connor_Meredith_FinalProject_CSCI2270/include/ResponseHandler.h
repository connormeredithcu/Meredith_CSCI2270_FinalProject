#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

//This struct handles edges in the response graph
struct ResponseChild;

//This struct contains the word associated to the response node, a vector of successors or children,
//and a record of the number of times the word has been used. E.g., the instance
// (key = "DOGS", children = <null>, numTimesUsed = 50)
//would indicate that the word "DOGS" has been entered 50 times and no word has ever been used
//directly afterwards.
struct ResponseNode
{
    string key;
    vector<ResponseChild> children;
    double numTimesUsed;

    ResponseNode (string name)
    {
        numTimesUsed = 0.0;
        key = name;
    }
};

//This structure contains an edge weight and location of a response node. E.g., the bracketed
//section of the following graph would be a single response child:
// I[--1->]run
//This would indicate that the word "run" has been used directly after the word "I" one time.
struct ResponseChild
{
    ResponseNode * child;
    double numTimesParented;
};

//My code uses a BST to organize the response nodes. This is simpler than using a BFS or DFS algorithm
//in the graph itself.
struct SearchNode
{
    //Standard BST relationship pointers
    SearchNode * parent;
    SearchNode * leftChild;
    SearchNode * rightChild;

    //The info held by each node in the tree is an address of a Response Node in the graph.
    //This way, we can perform in-order traversal of the graph and use BST search methods instead of
    //using Djikstra's algorithm, a BFS, or DFS.
    ResponseNode * key;
};

class ResponseHandler
{
    public:
        //This constructor just handles some basic initialization tasks.
        ResponseHandler();

        //Split a string based on a delimiter into a vector of sections
        vector<string> ParseString(string line, string delim);
        //Add a sentence to the BST and response graph
        void AddSentence (string sentence);
        //Given a node, randomly choose a child based on edge weight
        ResponseNode * GetChild(ResponseNode * parent);
        //Randomly choose a word with which to start a sentence based on usage amount
        ResponseNode * GetFirst();
        //This is a simpler function to find words in the response graph ***That you know exist***
        ResponseNode * FindExistingWord(string word);
        //Perform an in-order traversal of a subtree of the BST to display vertices, edges, and weights in the graph.
        void DisplayVerticesEdges(SearchNode * current);
        //Perform an in-order traversal of the whole BST to display vertices, edges, and weights in the graph.
        void DisplayGraph();
        //Same as above, but pre-order
        void PreDisplayVerticesEdges(SearchNode * current);
        void PreDisplayGraph();
        //Same as above, but post-order
        void PostDisplayVerticesEdges(SearchNode * current);
        void PostDisplayGraph();

        //Helper flag. This tells whether or not any words have been added to the BST.
        bool bSTInitialized;
        //This vector keeps track of the interactions between the program and user during a session.
        vector<string> sentences;
        //This vector keeps track of words that are used first in a sentence and their overall number of times used.
        vector<ResponseChild> firstWords;
    protected:
    private:
        //This pointer helps when connecting items in the graph. It points to the end_of_sentence RN
        SearchNode * eosHelper;
        //This points to a special response node. It is the "end of sentence" invisible word.
        ResponseNode * end_of_sentence;
        //This is the root of the BST.
        SearchNode * head;
};

#endif // RESPONSEHANDLER_H
