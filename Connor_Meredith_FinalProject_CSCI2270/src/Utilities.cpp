#include "Utilities.h"
#include <fstream>


//This utility function displays the options for the user
void DisplayMenu()
{
    cout << endl;
    cout << "Please select an option below:"    << endl
         << "1. Enter a sentence."              << endl
         << "2. Read in sentences from a file." << endl
         << "3. Have me say a sentence."        << endl
         << "4. Interact with me for a while."  << endl
         << "5. Exit program."                  << endl
         << "> "                                       ;
}

//This utility function handles option 1
void TakeSentence(ResponseHandler * g)
{
    string sentence;
    cout << "Please enter a sentence:" << endl
         << "> "                              ;
    getline(cin, sentence);
    g->AddSentence(sentence);
}

void ReadFileSentences(ResponseHandler * g)
{

}
