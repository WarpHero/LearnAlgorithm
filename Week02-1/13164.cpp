//HappyKindergarten
#include <iostream>
using namespace std;

#define MAX 300000

int Func(int num, int arr[], int N) {

	int diff = 0;
	int res = 0;
	for (int i = 1; i<N; i++) {
		if (diff >= arr[i+1] - arr[i]) {
			diff = arr[i+1] - arr[i];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int cnt = 0;

	int result = 0;

	cin >> N >> K;

	int* children = new int[N];
	int* diff = new int[K];

	for (int i = 0; i < N; i++) {
		cin >> children[i];
	}

	for (int i = N; i > 0; i--) {
		if (children[i] - children[i - 1] > 0) {
			diff[cnt] = children[i] - children[i - 1];
			cnt++;
		}
	}
	for(int i=0)

	if (K <= cnt) {
		int n = cnt - K + 1;

		

	}
	else {
		result = 0;
	}


	delete[] children;

	return 0;
}

