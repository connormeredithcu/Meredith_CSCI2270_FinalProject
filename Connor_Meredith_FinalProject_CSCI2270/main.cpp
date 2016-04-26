#include "ResponseHandler.h"
#include "Utilities.h"

using namespace std;

int main()
{
    ResponseHandler mimic = ResponseHandler();
    mimic.AddSentence("This is a test!");
    TakeSentence(&mimic);
    ReadFileSentences(&mimic);


    for (int i = 0; i < mimic.firstWords.size(); i++)
    {
        cout << mimic.firstWords.at(i).child->key << ":" << mimic.firstWords.at(i).numTimesParented << endl;
    }

    return 0;
}
