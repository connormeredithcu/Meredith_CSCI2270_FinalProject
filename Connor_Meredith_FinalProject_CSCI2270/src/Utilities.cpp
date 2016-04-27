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
         << "5. Display edges and vertices."    << endl
         << "6. Exit program."                  << endl
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

//This utility function attempts to read in sentences line-by-line from a text file.
void ReadFileSentences(ResponseHandler * g)
{
    ifstream infile;
    string fname;
    cout << "Please enter a filename:" << endl
         << "> "                              ;
    getline(cin, fname);
    infile.open(fname);

    if (!infile.good())
    {
        cout << "Could not open file successfully. Please check that it exists." << endl;
        return;
    }

    string line;
    while (getline(infile, line))
    {
        g->AddSentence(line);
    }

    cout << "Successfully read in sentences." << endl;
}

void GenerateSentence(ResponseHandler * g)
{
    ResponseNode * temp = g->GetFirst();
    while (temp->key != "")
    {
        cout << temp->key;
        temp = g->GetChild(temp);
        cout << " ";
    }
    cout << endl;
}
