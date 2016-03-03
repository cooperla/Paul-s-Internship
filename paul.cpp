#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int getLength(string word);

int main(){
	string word;
	int TempNum;
	cout<<"Please enter a word: "<<endl;
	cin>>word;
	int TempNum=getLength(word);
	char letterlist[TempNum];
	for (int i=0; i<=TempNum; i++){
		letterlist[i]=word[i];
		}
	int strikes=0;
	char secret[TempNum];
	while (strikes<6){
		if (letterlist==secret){
			cout<<"You win!"<<endl;
			return 0;
		}
		cout<<"You have this many wrong guesses left: "<<6-strikes<<endl;
		cout<<"Guess a letter: "<<endl;
		cin>>char ch;
		int found=word.find(ch);
		if (found>=0){
			cout<<"That letter is in the "<<found<<"spot in the word!"<<endl;
			secret[found]=ch;
		}
		if (found<0){
			cout<<"That letter is not in the word. +1 strike"<<endl;
			strikes++;
		}
		cout<<"You have figured out: ";
		for (int i=0; i<=TempNum; i++){
			cout<<secret[i]<<",";
		}
		cout<<endl;
	}
	cout<<"You lose! The word was: "<<word<<endl;
	return 0;
}

int getLength(string word){
	return word.size();
}