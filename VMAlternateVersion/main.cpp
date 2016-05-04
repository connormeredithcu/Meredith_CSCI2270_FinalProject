#include "ResponseHandler.h"
#include "Utilities.h"

using namespace std;

int main()
{
    ResponseHandler mimic = ResponseHandler();

    string choice = "";
    while (choice != "8")
    {
        DisplayMenu();
        cin >> choice;
        cin.ignore();
        if (choice == "1")
        {
            TakeSentence(&mimic);
        }
        else if (choice == "2")
        {
            MultipleInput(&mimic);
        }
        else if (choice == "3")
        {
            ReadFileSentences(&mimic);
        }
        else if (choice == "4")
        {
            GenerateSentence(&mimic);
        }
        else if (choice == "5")
        {
            GenerateMultiple(&mimic);
        }
        else if (choice == "6")
        {
            MultipleInteract(&mimic);
        }
        else if (choice == "7")
        {
            DisplayWithOptions(&mimic);
        }
        else if (choice == "8")
        {
            SaveAndQuit(&mimic);
        }
    }

    return 0;
}
