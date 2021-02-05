#ifndef INPUTFILE_H
#define INPUTFILE_H

#include <string>
#include <vector>

using namespace std;

class InputFile
{
public:
	InputFile(const string& f);
	void setInputFilename(const string& s) {inputFilename = s;}
	string getInputFilename() {return inputFilename;}
	void loadFileContents();
	void printFileContents();
	void removeAllPunctuation();
	void removePunctuation(string& p);
	void makeLowerCase();
	int getNumWords() {return fileContents.size();}
	string getWord(int i) {return fileContents[i];}
private:
	vector < string > fileContents;
	string inputFilename;
};

#endif