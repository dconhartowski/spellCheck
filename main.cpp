#include <iostream>
#include "Dictionary.h"
#include "InputFile.h"
#include "SpellChecker.h"
using namespace std;

int main()
{
	string dFile; //name of the dictionary file
	string iFile; //name of the input file
	char response = '1'; //response from the user

	//prompt for the path to the dictionary file
	cout<<"Enter the path to the dictionary: ";
	cin>>dFile;

	//prompt for the path to the input file
	cout<<"Enter the path to the input file: ";
	cin>>iFile;

	//create the spellchecker object passing it the 
	//path to the dictionary and the file to be checked
	SpellChecker sc(dFile, iFile);

	cout<<"Welcome to the spellcheck program"<<endl;

	//while the user wants to continue
	while(response != '3')
	{
		cout<<"1) Add a word to the dictionary"<<endl;
		cout<<"2) Perform a spellcheck on a file"<<endl;
		cout<<"3) Quit"<<endl;

		//get a response
		cin>>response;

		//if they want to add a word to the dictionary
		if(response == '1')
		{
			//ask the spellchecker to add a word
			sc.addAWord();
		}
		else if(response == '2') //do a spellcheck
		{
			//ask the spellchecker to do a spelcheck
			sc.spellCheck();
		}
	}	

	return 0;
}