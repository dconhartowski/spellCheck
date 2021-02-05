#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include "Dictionary.h"
#include "InputFile.h"
#include "MisspelledCollection.h"

#include <string>
#include <vector>

using namespace std;

class SpellChecker
{
public:
	SpellChecker(const string& dFile, const string& iFile);
	void spellCheck();
	void addAWord();
	void findMisspellings();
	void printSuggestions();
    void swapLetters(string w, vector < string >& words);
    void characterReplace(string w, vector < string >& words);
    void commonLetters(string w, int numLetters, vector < string >& words);
    void addWordToList(vector < string >& words, string w);

private:
	Dictionary dictionary;
	InputFile inputFile;
	MisspelledCollection mc;
};

#endif