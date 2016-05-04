#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "ResponseHandler.h"

//This will display the menu of options to the user.
void DisplayMenu();
//This will interact with the user and add one sentence to g's response graph
void TakeSentence(ResponseHandler * g);
//This will read sentences from a text file line by line and add each sentence to g's response graph
void ReadFileSentences(ResponseHandler * g);
//This will cause g to randomly create a pseudo-grammatical sentence and display it
void GenerateSentence(ResponseHandler * g);
//Same as previous, but repeated
void GenerateMultiple(ResponseHandler * g);
//Repeatedly allow the user to enter a sentence and have the program generate a sentence.
//This allows for conversation-like interactions.
void MultipleInteract(ResponseHandler * g);
//Display a menu of graph-display options. Ultimately, this displays the contents of g's response graph.
void DisplayWithOptions(ResponseHandler * g);
//Give the user an option to save their interactions in a text file.
void SaveAndQuit(ResponseHandler * g);

//Gives the user an option to input many sentences at once
//This is William John Van Patten's contribution
void MultipleInput(ResponseHandler * g);

//This is a helper function that converts a string to an integer. I didn't use std::stoi(std::string s) because
//I am not using the c++ 2011 standard.
int StringToInt(string text);

#endif // UTILITIES_H_INCLUDED
