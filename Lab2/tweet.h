#ifndef TWEET
#define TWEET

using namespace std;

#include <istream>
#include <ostream>

class Tweet{
 public:
	Tweet();
	Tweet(char* msg);
	
	~Tweet();
	
	// get tweet from stdin
	friend istream& operator>>(istream& fin,  Tweet& T);
	
	// dump tweet to stdout
	friend ostream& operator<<(ostream& fout, const Tweet& T);
	
	
	
 private:
	static const short MAX_TWEET;
	
	char* theTweet;
};

#endif