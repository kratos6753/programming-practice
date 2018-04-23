#include <stdio.h>
// convert fahrenheit to celsius

// formula used C = (5/9)*(F-32)

int main() {
	int lower, higher, step;
	int fahren, celcius;
	lower = 0;
	higher = 300;
	step = 20;
	fahren = lower;
	printf("%s\t%s\n", "fahren", "celcius");
	while(fahren <= higher) {
		celcius = (5.0/9)*(fahren - 32);
		printf("%5d\t%6d\n", fahren, celcius);
		fahren += step;
	}
	return 0;
}