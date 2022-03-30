#include <iostream>
#include <string>

/*
The idea is this:
A noun is an optional 'the' + 'birds'\'fish'\'C++'
A verb is 'rules'\'fly'\'swim'
A conjunction is 'and'\'or'\'but'
A sentence is 1) 'noun + verb .', or 2) 'sentence + conjunction + sentence .'.

The goal is to parse sentences and return "OK" or "NOT OK" after checking if the sentence fits the grammar.
*/

std::string word {};

bool isNoun();
bool isVerb();
bool isConjunction();
bool isSentence();

bool isCorrect()
{
    if (isSentence())
    {
        if (isConjunction())
            return isCorrect();
        else
        {
            if (word == ".")
                return true;
            else
                return false;
        }
    }
    else
        return false;
}

bool isSentence()
{
    std::cin >> word;
    if (isNoun())
    {
        return isVerb();
    }
    else
        return false;
}

bool isNoun()
{
    if (word == "the")
    {
        std::cin >> word;
        return isNoun();
    }
    else if (word == "birds" || word == "fish" || word == "C++")
        return true;
    return false;
}

bool isVerb()
{
    std::cin >> word;
    if (word == "rules" || word == "fly" || word == "swim")
        return true;
    else
        return false;
}

bool isConjunction()
{
    std::cin >> word;
    if (word == "but" || word == "or" || word == "and")
        return true;
    else
        return false;
}

int main()
{
    while (word != "quit")
    {
        if (isCorrect())
            std::cout << "OK!" << std::endl;
        else
        {
            std::cout << "NOT OK!" << std::endl;
            std::cin.ignore(1000, '\n');
        }
    }
    std::cout << "Quitting";
    return 0;
}