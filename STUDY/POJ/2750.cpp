//2750
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	vector<int> v;
	cin >> N;
	while (N) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		N--;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}