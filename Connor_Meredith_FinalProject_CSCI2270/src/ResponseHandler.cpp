#include "ResponseHandler.h"

ResponseHandler::ResponseHandler()
{
    head = new SearchNode;
    head->key = nullptr;
    head->leftChild = nullptr;
    head->rightChild = nullptr;
    head->parent = nullptr;
    bSTInitialized = false;

    end_of_sentence = new ResponseNode ("");
    end_of_sentence->numTimesUsed = 0;
    //ctor
}

vector<string> ResponseHandler::ParseString(string line, string delim)
{
    vector<string> parsedString;
    int pos1 = 0; int pos2 = line.find(delim);
    while (pos1 >=0)
    {
        parsedString.push_back(line.substr(pos1, pos2-pos1));
        pos1 = pos2+1;
        pos2 = line.find(delim, pos1);
        if (pos1 == 0)
            break;
    }
    return parsedString;
}
