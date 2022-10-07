//2775
#include <iostream>
using namespace std;

int APTfunc(int k, int n) {
	if (k == 0 || n == 1) return n;

	return APTfunc(k - 1, n) + APTfunc(k, n - 1);
}

int main() {
	int T, k, n;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		int tmp = APTfunc(k, n);
		printf("%d \n",tmp);

	}

	return 0;
}