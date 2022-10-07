//4948
#include <iostream>
using namespace std;
int arr[246913];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i <= 123456; i++) {
		for (int j = 2; i * j <= (2 * 123456); j++) {
			arr[i * j] = 1;
		}
	}
	for (int i = 2; i < 246913;i++) {
		if (arr[i] == 0) arr[i] = 1;
		else arr[i] = 0;
	}
	//for (int i = 2; i < 264913; i++) {
	//	arr[i] += arr[i - 1]; //runtime error
	//}
	int n;
	while (1) {
		cin >> n;
		if(n==0) return 0;
		int cnt = 0;
		for (int i = n + 1; i <= (2 * n); i++) {
			cnt += arr[i];
		}
		/*cout << arr[2 * n] - arr[n] << "\n";*/
		cout << cnt << "\n";
	}
	return 0;
}