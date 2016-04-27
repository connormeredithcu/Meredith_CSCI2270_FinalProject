#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "ResponseHandler.h"

void DisplayMenu();
void TakeSentence(ResponseHandler * g);
void ReadFileSentences(ResponseHandler * g);
void GenerateSentence(ResponseHandler * g);
void MultipleInteract(ResponseHandler * g);

int StringToInt(string text);

#endif // UTILITIES_H_INCLUDED
