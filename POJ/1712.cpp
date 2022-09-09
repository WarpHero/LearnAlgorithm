//1712
#include <iostream>
using namespace std;

int main() {
	int A, B, C;

	cin >> A >> B >> C;

	if (B >= C) cout << -1 << endl;
	else {
		int tmp;
		tmp = (A / (C - B)) + 1;
		printf("%d", tmp);
	}

	return 0;
}