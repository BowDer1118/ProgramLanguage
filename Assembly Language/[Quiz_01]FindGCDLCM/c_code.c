#include <stdio.h>

extern int gcd(int a, int b);

int gcd(int a, int b) {
	//search gcd of a and b
	int temp = 0;
	while (a != 0) {
		temp = b % a;
		b = a;
		a = temp;
	}
	return b;
}

