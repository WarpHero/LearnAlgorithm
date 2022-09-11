//2581
#include <iostream>
using namespace std;
int cnt, sum;
int minPrime = 10001;
void FindPRimeNSum(int num) {
	int div = num / 2;

	if (div == 1) {
		if (minPrime >= num) minPrime = num;
		cnt++;
		sum += num;
		return;
	}
	while (div > 1) {
		if (num % div == 0) return;

		div--;
	}

	if (minPrime >= num) minPrime = num;
	cnt++;
	sum += num;
}

int main() {
	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if(i!=1) FindPRimeNSum(i);
	}
	
	if (cnt == 0) cout << -1;
	else { cout << sum << "\n"<< minPrime; }
	return 0;
}