//1978
#include <iostream>

using namespace std;
int cnt = 0;

void FindPrime(int num) {
	int div = num / 2;
	if (div == 1) {
		cnt++;
		return;
	}
	while (div > 1) {

		if (num % div == 0) return;
		else div--;
	}
	cnt++;
	return;

}
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num != 1) {
			FindPrime(num);
		}
	}
	cout << cnt;

	return 0;
}