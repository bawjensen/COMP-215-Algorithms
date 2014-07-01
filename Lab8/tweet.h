#ifndef TWEET
#define TWEET

#include <iostream>
#include <istream>
#include <ostream>
#include <cstring>

using namespace std;

const short MAX_TWEET_LENGTH = 140;     // have to assign constant in .cpp file
class Tweet {
private:
	static const short MAX_TWEET = MAX_TWEET_LENGTH;
	
	char* tweetText;
public:
	Tweet();
	Tweet(char[]);
	Tweet(const Tweet&);
	~Tweet();

	Tweet& operator=(const Tweet&);
	
	// ====== FRIENDS ==================================
	// get tweet from stdin
	friend istream& operator>>(istream& fin,  Tweet& T);
	
	// dump tweet to stdout
	friend ostream& operator<<(ostream& fout, const Tweet& T);
}; // end class Tweet


#endif