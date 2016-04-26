#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include <iostream>
#include <vector>

using namespace std;

struct ResponseChild;

struct ResponseNode
{
    string name;
    vector<ResponseChild> children;
    double numTimesUsed;
};

struct ResponseChild
{
    ResponseNode * child;
    double numTimesParented;
};

class ResponseHandler
{
    public:
        ResponseHandler();

        vector<string> ParseString(string line, string delim);
    protected:
    private:
};

#endif // RESPONSEHANDLER_H
