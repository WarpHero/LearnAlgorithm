//CowGotchi
//시간초과
#include <iostream>
using namespace std;

int cnt = 2;
long long int Survive(long long int num1, long long int num2) {
	
	if (num1 == 1 && num2 == 1) return (int)cnt;

	else {
		cnt++;
		num1 /= 2;
		if (num1 == 1 && num2 > 1) {
			num1++;
			num2--;
		}
		return Survive(num1, num2);
	}
	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, day;

	long long int n, m;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		day = Survive(n, m);
		printf("%d \n", day);

	}

	return 0;
}