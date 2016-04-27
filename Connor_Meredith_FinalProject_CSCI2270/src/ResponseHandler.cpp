#include "ResponseHandler.h"

ResponseHandler::ResponseHandler()
{
    head = new SearchNode;
    head->key = nullptr;
    head->leftChild = nullptr;
    head->rightChild = nullptr;
    head->parent = nullptr;
    bSTInitialized = false;

    end_of_sentence = new ResponseNode ("");
    end_of_sentence->numTimesUsed = 0;
    eosHelper = new SearchNode;
    eosHelper->key = end_of_sentence;
    //ctor
}

vector<string> ResponseHandler::ParseString(string line, string delim)
{
    vector<string> parsedString;
    int pos1 = 0; int pos2 = line.find(delim);
    while (pos1 >=0)
    {
        parsedString.push_back(line.substr(pos1, pos2-pos1));
        pos1 = pos2+1;
        pos2 = line.find(delim, pos1);
        if (pos1 == 0)
            break;
    }
    return parsedString;
}

ResponseNode * ResponseHandler::FindExistingWord (string word)
{
    SearchNode * temp = head;
    while (temp)
    {
        if (temp->key->key == word)
        {
            return temp->key;
        }
        if (word.compare(temp->key->key) < 0)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    return nullptr;
}

void ResponseHandler::AddSentence(string sentence)
{
    if (sentence == "")
    {
        return;
    }
    sentences.push_back(sentence);
    vector<string> words = ParseString(sentence, " ");

    vector<SearchNode*> wordLocations;

    //We want to add each word in the sentence to the BST and graph
    for (int i = 0; i < words.size(); i++)
    {
        //Yay, we're entering our very first word.
        if (!bSTInitialized)
        {
            head->key = new ResponseNode(words.at(i));

            bSTInitialized = true;
            wordLocations.push_back(head);
            //cout << "Added " << head->key->key << " to the words to connect!" << endl;

            continue;
        }

        //Other words exist in the BST, so we need to find the destination of the new word
        SearchNode * temp = head;
        string testWord = words.at(i);
        while (temp)
        {
            if (temp->key->key == testWord)
            {
                break;
            }
            else if (testWord.compare(temp->key->key) < 0)
            {
                //If there IS a left child to which we can switch, then switch
                if (temp->leftChild)
                {
                    temp = temp->leftChild;
                }
                //Otherwise, we need to create a new left child with the relevant info.
                else
                {
                    temp->leftChild = new SearchNode;
                    temp->leftChild->key = new ResponseNode (testWord);
                    temp->leftChild->parent = temp;
                    temp->leftChild->leftChild = nullptr;
                    temp->leftChild->rightChild = nullptr;

                    temp = temp->leftChild;

                    break;
                }
            }
            else if (testWord.compare(temp->key->key) > 0)
            {
                //If there IS a right child to which we can switch, then switch
                if (temp->rightChild)
                {
                    temp = temp->rightChild;
                }
                //Otherwise, we need to create a new left child with the relevant info.
                else
                {
                    temp->rightChild = new SearchNode;
                    temp->rightChild->key = new ResponseNode (testWord);
                    temp->rightChild->parent = temp;
                    temp->rightChild->leftChild = nullptr;
                    temp->rightChild->rightChild = nullptr;

                    temp = temp->rightChild;

                    break;
                }
            }
        }

        wordLocations.push_back(temp);
        //cout << "Added " << temp->key->key << " to the words to connect!" << endl;
    }
    wordLocations.push_back(eosHelper);

    //We have now added every word to the BST and we have a vector of the nodes in the BST that were
    //in the entered sentence. Now, we have to connect the words and update weights.
    for (int i = 0; i < wordLocations.size()-1; i++)
    {
        ResponseNode * parentWord = wordLocations.at(i)->key;
        ResponseNode * childWord = wordLocations.at(i+1)->key;

        parentWord->numTimesUsed++;

        //Test to see if the edge already exists. If it does, then update the edge weight
        bool edgeExists = false;
        for (int j = 0; j < parentWord->children.size() && !edgeExists; j++)
        {
            if (parentWord->children.at(j).child->key == childWord->key)
            {
                parentWord->children.at(j).numTimesParented++;

                edgeExists = true;
            }
        }

        //The edge does not exist. We need to create a new edge.
        if (!edgeExists)
        {
            ResponseChild newEdge;
            newEdge.child = childWord;
            newEdge.numTimesParented = 1.0;
            parentWord->children.push_back(newEdge);
        }

        //cout << "Finished connecting " << parentWord->key << " and " << childWord->key << " !" << endl;
    }

    //Finally, we just add the first word to our first word variable or update an existing entry
    string firstWord = words.at(0);
    bool flag = true;
    for (int i = 0; i < firstWords.size(); i++)
    {
        if (firstWords.at(i).child->key == firstWord)
        {
            firstWords.at(i).numTimesParented++;
            flag = false;
            break;
        }
    }
    //In this case, we've never used this certain word as the first word in the sentence
    if (flag)
    {
        ResponseNode * tmp = FindExistingWord(firstWord);
        ResponseChild tempest;
        tempest.child = tmp;
        tempest.numTimesParented = 1;
        firstWords.push_back(tempest);
    }

}

ResponseNode * ResponseHandler::GetChild(ResponseNode * parent)
{
    vector<ResponseChild> choices = parent->children;
    if (choices.size() == 0)
        return nullptr;
    vector<double> weights;
    vector<int> helper;
    for (int i = 0; i < choices.size(); i++)
    {
        weights.push_back( (double) choices.at(i).numTimesParented);
    }

    for (int i = 0; i < choices.size(); i++)
    {
        for (int j = 0; j < weights.at(i); j++)
        {
            helper.push_back(i);
        }
    }

    int k = helper.size();
    int index = rand() % k;
    return choices.at(helper.at(index)).child;
}

ResponseNode * ResponseHandler::GetFirst()
{
    vector<ResponseChild> choices = firstWords;
    if (choices.size() == 0)
        return nullptr;
    vector<double> weights;
    vector<int> helper;
    for (int i = 0; i < choices.size(); i++)
    {
        weights.push_back( (double) choices.at(i).numTimesParented);
    }

    for (int i = 0; i < choices.size(); i++)
    {
        for (int j = 0; j < weights.at(i); j++)
        {
            helper.push_back(i);
        }
    }

    int k = helper.size();
    int index = rand() % k;
    return choices.at(helper.at(index)).child;
}

void ResponseHandler::DisplayVerticesEdges(SearchNode * current)
{
    if (current->leftChild)
    {
        DisplayVerticesEdges(current->leftChild);
    }
    cout << current->key->key << ": ";
    for (int i = 0; i < current->key->children.size()-1; i++)
    {
        string childName = current->key->children.at(i).child->key;
        if (childName == "")
            childName = "END_OF_SENTENCE";
        int weight = current->key->children.at(i).numTimesParented;
        cout << "(" << childName << ", " << weight << "), ";
    }
    string childName = current->key->children.at(current->key->children.size()-1).child->key;
    if (childName == "")
        childName = "END_OF_SENTENCE";
    int weight = current->key->children.at(current->key->children.size()-1).numTimesParented;
    cout << "(" << childName << ", " << weight << ").";
    cout << endl;
    if (current->rightChild)
    {
        DisplayVerticesEdges(current->rightChild);
    }
}

void ResponseHandler::DisplayGraph()
{
    DisplayVerticesEdges(head);
}

void ResponseHandler::PreDisplayVerticesEdges(SearchNode * current)
{
    cout << current->key->key << ": ";
    for (int i = 0; i < current->key->children.size()-1; i++)
    {
        string childName = current->key->children.at(i).child->key;
        if (childName == "")
            childName = "END_OF_SENTENCE";
        int weight = current->key->children.at(i).numTimesParented;
        cout << "(" << childName << ", " << weight << "), ";
    }
    string childName = current->key->children.at(current->key->children.size()-1).child->key;
    if (childName == "")
        childName = "END_OF_SENTENCE";
    int weight = current->key->children.at(current->key->children.size()-1).numTimesParented;
    cout << "(" << childName << ", " << weight << ").";
    cout << endl;

    if (current->leftChild)
    {
        DisplayVerticesEdges(current->leftChild);
    }
    if (current->rightChild)
    {
        DisplayVerticesEdges(current->rightChild);
    }
}

void ResponseHandler::PostDisplayVerticesEdges(SearchNode * current)
{
    if (current->leftChild)
    {
        DisplayVerticesEdges(current->leftChild);
    }
    if (current->rightChild)
    {
        DisplayVerticesEdges(current->rightChild);
    }
    cout << current->key->key << ": ";
    for (int i = 0; i < current->key->children.size()-1; i++)
    {
        string childName = current->key->children.at(i).child->key;
        if (childName == "")
            childName = "END_OF_SENTENCE";
        int weight = current->key->children.at(i).numTimesParented;
        cout << "(" << childName << ", " << weight << "), ";
    }
    string childName = current->key->children.at(current->key->children.size()-1).child->key;
    if (childName == "")
        childName = "END_OF_SENTENCE";
    int weight = current->key->children.at(current->key->children.size()-1).numTimesParented;
    cout << "(" << childName << ", " << weight << ").";
    cout << endl;
}

void ResponseHandler::PreDisplayGraph()
{
    PreDisplayVerticesEdges(head);
}

void ResponseHandler::PostDisplayGraph()
{
    PostDisplayVerticesEdges(head);
}
