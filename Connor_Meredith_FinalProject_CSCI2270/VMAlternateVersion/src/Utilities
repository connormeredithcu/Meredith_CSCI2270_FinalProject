#include "Utilities.h"
#include <fstream>


//This utility function displays the options for the user
void DisplayMenu()
{
    cout << endl;
    cout << "Please select an option below:"        << endl
         << "1. Enter a sentence."                  << endl
         << "2. Read in sentences from a file."     << endl
         << "3. Have me say a sentence."            << endl
         << "4. Have me say a bunch of sentences."  << endl
         << "5. Interact with me for a while."      << endl
         << "6. Display edges and vertices."        << endl
         << "7. Exit program."                      << endl
         << "> "                                           ;
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

    infile.close();

    cout << "Successfully read in sentences." << endl;

}

void GenerateSentence(ResponseHandler * g)
{
    if (!g->bSTInitialized)
    {
        cout << "Please enter some sentences first! I don't know how to talk yet." << endl;
        return;
    }
    ResponseNode * temp = g->GetFirst();
    while (temp->key != "")
    {
        cout << temp->key;
        temp = g->GetChild(temp);
        cout << " ";
    }
    cout << endl;
}

void GenerateMultiple(ResponseHandler * g)
{
    string sNum;
    cout << "How many sentences should I say?" << endl
         << "> "                                           ;
    cin >> sNum;
    cin.ignore();
    int intNum = StringToInt(sNum);
    for (int i = 0; i < intNum; i++)
        GenerateSentence(g);
}

int StringToInt(string text)
{
    stringstream converter (text);
    int result;
    if (!(converter >> result))
        result = 0;
    return result;
}

void MultipleInteract(ResponseHandler * g)
{
    string sInteractions;
    cout << "How many interactions should we have?" << endl
         << "> "                                           ;
    cin >> sInteractions;
    cin.ignore();
    int numInteractions = StringToInt(sInteractions);

    for (int i = 0; i < numInteractions; i++)
    {
        TakeSentence(g);
        GenerateSentence(g);
    }

}

void DisplayWithOptions(ResponseHandler * g)
{
    if (!g->bSTInitialized)
    {
        cout << "Sorry, but there is nothing to display. Please enter some sentences or read in a memory file." << endl;
        return;
    }
    cout << "How would you like the BST to be traversed?" << endl
         << "1. In order"                                 << endl
         << "2. Post order"                               << endl
         << "3. Pre order"                                << endl
         << "> "                                                 ;
    string choice;
    cin >> choice;
    if (choice == "1")
    {
        g->DisplayGraph();
    }
    else if (choice == "2")
    {
        g->PostDisplayGraph();
    }
    else if (choice == "3")
    {
        g->PreDisplayGraph();
    }
}

void SaveAndQuit(ResponseHandler * g)
{
    string x;
    cout << "Would you like to save this session?" << endl
         << "1. Yes"                               << endl
         << "2. No"                                << endl
         << "> "                                          ;
    cin >> x;
    if (x != "1")
        return;

    cout << "Please enter a filename with no extension in which the session will be saved:" << endl
         << "> ";
    string fname;
    cin >> fname;
    ofstream outFile (fname + ".txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < g->sentences.size(); i++)
        {
            string line = g->sentences.at(i) + "\n";
            outFile << line;
        }
        outFile.close();
    }
    else
        cout << "Could not open memory file." << endl;
}
