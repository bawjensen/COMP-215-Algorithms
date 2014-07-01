//
//  mainTweet.cpp
//  Xcode_Project
//
//  Created by Mark LeBlanc on 9/10/13.
//  Copyright (c) 2013 Mark LeBlanc. All rights reserved.
//

#include <iostream>

#include "tweet.h"

int main()
{
	char t[256] = "foobar goes to the races";
	Tweet T(t);
	{
		Tweet S = T;
		cout << S << endl;
	}
	
	cout << T << endl;
	
	
	
	return 0;
}