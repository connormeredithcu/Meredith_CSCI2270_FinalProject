#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include <iostream>
#include <vector>

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
        numTimesUsed = 0;
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
    SearchNode * parent;
    SearchNode * leftChild;
    SearchNode * rightChild;

    ResponseNode * key;
};

class ResponseHandler
{
    public:
        ResponseHandler();

        vector<string> ParseString(string line, string delim);
    protected:
    private:
        SearchNode * head;
        bool bSTInitialized;

        ResponseNode * end_of_sentence;
};

#endif // RESPONSEHANDLER_H
