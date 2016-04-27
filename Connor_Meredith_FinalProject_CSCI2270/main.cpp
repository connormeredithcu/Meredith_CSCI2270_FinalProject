#include "ResponseHandler.h"
#include "Utilities.h"

using namespace std;

int main()
{
    ResponseHandler mimic = ResponseHandler();
    //mimic.AddSentence("This is a test!");
    //TakeSentence(&mimic);
    ReadFileSentences(&mimic);
    MultipleInteract(&mimic);
    SaveAndQuit(&mimic);

    return 0;
}
