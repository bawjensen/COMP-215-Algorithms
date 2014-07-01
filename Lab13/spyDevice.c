#include <stdio.h>

struct spyDevice {
	char lightsOn;
	char ownerIn;
	char strangersPresent;
	char safeLocked;
	char computerOnline;
	char workDayFinished;
	char neurotoxinPresent;
	char doorLocked;
};

int main() {
	spyDevice* deviceArray;

	printf("%lu\n", sizeof(spyDevice) * 1000);
}