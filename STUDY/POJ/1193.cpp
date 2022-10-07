//1193
#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;

	if (X == 1) printf("%d/%d", X, X);
	else {
		int sum = 1;
		int cnt = 2;
		int A, B; 
		while (X > sum) {
			sum += cnt;
			cnt++;
		}
		cnt--;
		if (cnt % 2 == 0) {
			int tmp = (sum - X);
			B = (tmp + 1);
			A = cnt - B + 1;
		}
		else {
			int tmp = (sum - X);
			A = (tmp + 1);
			B = cnt - A + 1;
		}

		printf("%d/%d", A, B);
	}
	
	return 0;
}