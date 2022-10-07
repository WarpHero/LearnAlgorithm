//9020
#include <iostream>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i < 10001; i++) {
		for (int j = 2; i * j <= 10000; j++) {
			arr[i * j] = 1;
		}
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		int tmp = num / 2;
		while (1) {
			if (arr[tmp] == 0 && arr[num - tmp] == 0) {
				cout << tmp << " " << num - tmp << "\n";
				break;
			}
			else {
				tmp--;
			}
		}
	}
	return 0;
}