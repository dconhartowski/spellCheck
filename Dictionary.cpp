#include <iostream>
#include <fstream>

#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
	setDictionaryFilename("W:/source/sortedwords.txt");
    loadDictionary();
	setOrigDictionarySize(dictionary.size());
}
Dictionary::Dictionary(const string filename)
{
    setDictionaryFilename(filename);
    loadDictionary();
	setOrigDictionarySize(dictionary.size());
}
Dictionary::~Dictionary()
{
	if(dictionary.size() > getOrigDictionarySize())
	{
		cout<<"Writing a new file back to the dictionary"<<endl;
		ofstream outfile(getDictionaryFilename().c_str());
		for(int i = 0;i < getOrigDictionarySize();i++)
		{
		outfile<<dictionary[i]<<endl;
		}
	}
}
void Dictionary::loadDictionary()
{
    ifstream infile(getDictionaryFilename().c_str());
    if(infile)
    {
        string temp; 
        infile>>temp;
        while(infile)
        {
           dictionary.push_back(temp);
            infile>>temp;
        }
    }
    else 
    {
        cout<<"Error opening "<<getDictionaryFilename()<<endl;
		exit(0);
    }
}
bool Dictionary::searchForWord(const string w)
{
    bool retVal = false;
	for(int i = 0;i < dictionary.size();i++)
	{
		if(dictionary[i] == w)
		{
			retVal = true;
			break;
		}
	}
	return retVal;
}
void Dictionary::printDictionary()
{
	for(int i = 0;i < dictionary.size();i++)
	{
		cout<<dictionary[i]<<endl;
	}
}
void Dictionary::addWordToDictionary(const string w)
{
	dictionary.push_back(w);
}