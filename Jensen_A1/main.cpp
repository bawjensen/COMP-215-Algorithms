#include <iostream>

using namespace std;

int main()
{
	char buffer[5];
	for (int count(0); cin; ++count) {
		if (cin.get(buffer, 5)) {
			cout << "get[" << count << "]='" << buffer << "'\n";
		}
		else {
			cout << "get[" << count << "] failed\n";
		}
	}
}