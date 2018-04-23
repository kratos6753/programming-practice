#include <stdio.h>
// convert celcius to farenheit

// formula used F = 32+ (9/5)*C

int main() {
	int lower, higher, step;
	int fahren, celcius;
	lower = 0;
	higher = 300;
	step = 20;
	celcius = lower;
	printf("%s\t%s\n", "celcius", "fahren");
	for(celcius = higher; celcius >= lower; celcius -= step) {
		fahren = 32 + (9.0/5)*celcius;
		printf("%5d\t%6d\n", celcius, fahren);
	}
	return 0;
}