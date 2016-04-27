#include "ResponseHandler.h"
#include "Utilities.h"

using namespace std;

int main()
{
    ResponseHandler mimic = ResponseHandler();
    //mimic.AddSentence("This is a test!");
    //TakeSentence(&mimic);
    ReadFileSentences(&mimic);

    for (int i = 0; i < 30; i++)
        GenerateSentence(&mimic);

    return 0;
}
