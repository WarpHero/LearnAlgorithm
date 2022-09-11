//1929
//함수 이용해서 풀면 시간초과 나옴
#include <iostream>
using namespace std;
int arr[1000001] = { 0 };
int main() {
	int M, N;
	cin >> M >> N;
	arr[1] = 1;
	for (int i = 2; i < N+1; i++) {
		for (int j = 2; j * i < (N+1); j++) {
			arr[i * j] = 1;
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] == 0) printf("%d\n", i);
	}

	return 0;
}