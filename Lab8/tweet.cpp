#include "tweet.h"

using namespace std;


Tweet::Tweet() {
	this->tweetText = 0;
}

Tweet::Tweet(char textString[]) {
	this->tweetText = new char[strlen(textString)];

	strcpy(this->tweetText, textString);
}

Tweet::Tweet(const Tweet& other) {
	this->tweetText = new char[strlen(other.tweetText)];

	strcpy(this->tweetText, other.tweetText);
}

Tweet::~Tweet() {
	cout << "Destroying " << this->tweetText;
	delete[] this->tweetText;
	cout << " -- destroyed." << endl;
}

Tweet& Tweet::operator=(const Tweet& other) {
	this->tweetText = new char[strlen(other.tweetText)];

	strcpy(this->tweetText, other.tweetText);
}




// ========= FRIENDS ===========================

// get tweet from stdin
istream& operator>>(istream& fin, Tweet& T) {
	// make a temporary array of chars to hold the tweet
	char line[Tweet::MAX_TWEET + 1];
	
	// read a line (upto MAX_TWEET chars only)
	fin.getline(line, Tweet::MAX_TWEET);
	
	// exercise for the reader:
	// what if the line had more than MAX_TWEET chars? what to do with them?

	// store temp array into the object
	// but what about the previous tweet stored here?
	if (T.tweetText) {
		delete[] T.tweetText;
	}
	
	// YOU comment these lines
	T.tweetText = new char[strlen(line)+1];
	strcpy(T.tweetText, line);
	
	return fin;
}

// dump tweet to stdout
ostream& operator<<(ostream& fout, const Tweet& T) {
	fout << "======================================" << endl;
	fout << "Tweet: " << endl
		 <<  T.tweetText << endl;
	fout << "======================================" << endl << endl;
	
	return fout;
}