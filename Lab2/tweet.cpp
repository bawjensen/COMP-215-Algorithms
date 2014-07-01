#include <iostream>

#include "tweet.h"

using namespace std;

const short Tweet::MAX_TWEET = 140;     // have to set constant in .cpp file

Tweet::Tweet() {
	this->theTweet = 0;
}

Tweet::Tweet(char* t) {
	this->theTweet = t;
}

Tweet::~Tweet() {

}

istream& operator>>(istream& fin,  Tweet& T) {
	fin >> T.theTweet;
	return fin;
}

ostream& operator<<(ostream& fout, const Tweet& T) {
	fout << T.theTweet;
	return fout;
}
