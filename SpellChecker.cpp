#include "SpellChecker.h"

#include <iostream>

using namespace std;

SpellChecker::SpellChecker(const string& dFile, const string& iFile)
: dictionary(dFile), inputFile(iFile) 
{
}
//******************************
void SpellChecker::addAWord()
{
	string w;
	cout<<"Enter the word to add to the dictionary: ";
	cin>>w;
	dictionary.addWordToDictionary(w);
}
//******************************
void SpellChecker::spellCheck()
{
	inputFile.removeAllPunctuation();
	findMisspellings();
	printSuggestions();
}
//******************************************
void SpellChecker::findMisspellings()
{
	for(int i = 0;i < inputFile.getNumWords();i++)
	{
		if(!dictionary.searchForWord(inputFile.getWord(i)))
		{	
			//add a word to the collection of misspelled words
			mc.addWord(inputFile.getWord(i));
		}
	}
}
//******************************************
void SpellChecker::printSuggestions()
{
	for(int i = 0;i < mc.getNumWords();i++)
	{
		//dynamically sized vector to hold suggestions
		vector < string > words;
		
		cout<<mc.getWord(i)<<" is misspelled"<<endl;
		cout<<"Here are some suggestions"<<endl;

		//this function will swap every two letters because
		//this is a common error
		swapLetters(mc.getWord(i), words);

		//this function will look for words that begin
		//with the same first four letters
		commonLetters(mc.getWord(i), 3, words);
	    
		//this function will replace each character
		//in the misspelled word with every other
		//character in the alphabet and check to see if
		//it is a valid word
		characterReplace(mc.getWord(i), words);

		//print all suggestions
		for(int i = 0;i < words.size();i++)
		{
			cout<<"\t"<<words[i]<<endl;
		}
		
		cout<<endl;
	}
}
//*********************************************************
void SpellChecker::swapLetters(string w, 
                               vector < string >& words)
{
    string tempString = w;
    for(int i = 1;i < w.length();i++)
    {
        char temp = tempString.at(i - 1);
        tempString.at(i - 1) = tempString.at(i);
        tempString.at(i) = temp;

		if(dictionary.searchForWord(tempString))
        {
            //if it is not misspelled, then 
            //it is a good suggestion, add it to the vector
            addWordToList(words, tempString);
        }
        tempString = w;
    }
}
//********************************************************
void SpellChecker::commonLetters(string w, int numLetters, 
                                 vector < string >& words)
{
    //temporary strings to hold the first characters
    //of the misspelled word and the words in the dictionary
    
    //might want more descriptive names than tempString1 and tempString2
    string tempString1;
    string tempString2;
    string dictWord;

    //if the string can be subdivided
    if(numLetters < w.length())
    {
        //look at each word in the dictionary
		for(int i = 0;i < dictionary.getNumWords();i++)
        {
            //load the first characters of the misspelled 
            //word into the temporary string
            tempString1 = w.substr(0 , numLetters);

            //load the word from the dictionary
            tempString2 = dictionary.getWord(i).substr(0 , numLetters);

            if(tempString2.compare(tempString1) == 0)
            {
                //add to list
                addWordToList(words, dictionary.getWord(i));
            }
        }
    }
}
//**********************************************************
void SpellChecker::characterReplace(string w, 
                                    vector < string >& words)
{
    //an array of all the characters in the alphabet
    static char keys[26] = {'a', 'b', 'c', 'd', 
                            'e', 'f', 'g', 'h', 
                            'i', 'j', 'k', 'l', 
                            'm', 'n', 'o', 'p', 
                            'q', 'r', 's', 't', 
                            'u', 'v', 'w', 'x', 
                            'y', 'z'};

    string tempString;

    //for each letter in the misspelled word
    for(int letterCounter = 0;
        letterCounter < w.length();
        letterCounter++)
    {
        //for each letter in the alphabet
        for(int alphaCounter = 0;alphaCounter < 26;alphaCounter++)
        {
            //store the misspelled word in 
            //a temporary string
            tempString = w;

            //replace each letter with a new letter of the alphabet
            tempString[letterCounter] = keys[alphaCounter];

            //check to see if this is not misspelled
			if(dictionary.searchForWord(tempString))
            {
                //if it is not misspelled, then 
                //it is a good suggestion, print to the screen
                addWordToList(words, tempString);
            }
        }
    }
}
//***************************************************************
void SpellChecker::addWordToList(vector < string >& words,
                                 string w)
{
    //only add to the list if its not already there
    bool add = true;

    for(int i = 0;i < words.size();i++)
    {
        //word already present
        if(words[i].compare(w) == 0)
        {
            add = false;
        }
    }
    if(add)//if we should add then push it on the vector
    // I don't think the above will ever work because there's no
    // condition in the if statement to be met.
    {
        words.push_back(w);
    }
}
