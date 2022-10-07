//2869
#include <iostream>
using namespace std;

int main() {
	int A, B, V;

	cin >> A >> B >> V;

	int day = 1;
	V = V - A;
	int tmp = A - B;
	day += (V / tmp);
	if ((V % tmp) != 0) {
		day++;
	}

	cout << day;
	return 0;

}