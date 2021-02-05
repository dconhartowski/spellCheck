#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <vector>

using namespace std;

class Dictionary
{
public:
    Dictionary(); //ctors
    Dictionary(const string filename);
	~Dictionary();

	void loadDictionary();
	void addWordToDictionary(const string w);
	bool searchForWord(const string w);
	void printDictionary();

	void setDictionaryFilename(const string s) {dictionaryFilename = s;}
	string getDictionaryFilename() {return dictionaryFilename;}
	void setOrigDictionarySize(const int s) {origDictionarySize = s;}
	int getOrigDictionarySize() {return origDictionarySize;}
	int getNumWords() {return dictionary.size();}
	string getWord(int i) {return dictionary[i];}
private:
    //most common words in english language
    vector < string > dictionary;
	string dictionaryFilename;
	int origDictionarySize;
};

#endif