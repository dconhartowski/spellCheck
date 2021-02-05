#ifndef MISSPELLEDCOLLECTION_H
#define MISSPELLEDCOLLECTION_H

#include <string>
#include <vector>

using namespace std;

class MisspelledCollection
{
public:
	MisspelledCollection();
	void addWord(const string& w) {misspelledWords.push_back(w);}
	int getNumWords() {return misspelledWords.size();}
	string getWord(int i) {return misspelledWords[i];}

private:
	vector < string > misspelledWords;
};

#endif