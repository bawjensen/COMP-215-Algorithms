#include "Jensen_A3.h"

using namespace std;

int main() {
	DEMData_Reader reader;

	reader.getFileData();
	reader.tableOutput();

	return 0;
}