#include "ResponseHandler.h"
#include "Utilities.h"

using namespace std;

int main()
{
    ResponseHandler mimic = ResponseHandler();
    //mimic.AddSentence("This is a test!");
    //TakeSentence(&mimic);

    string choice = "";
    while (choice != "7")
    {
        DisplayMenu();
        cin >> choice;
        if (choice == "1")
        {
            cin.ignore();
            TakeSentence(&mimic);
        }
        else if (choice == "2")
        {
            cin.ignore();
            ReadFileSentences(&mimic);
        }
        else if (choice == "3")
        {
            GenerateSentence(&mimic);
        }
        else if (choice == "4")
        {
            GenerateMultiple(&mimic);
        }
        else if (choice == "5")
        {
            MultipleInteract(&mimic);
        }
        else if (choice == "6")
        {
            DisplayWithOptions(&mimic);
        }
        else if (choice == "7")
        {
            SaveAndQuit(&mimic);
        }
    }

    return 0;
}
