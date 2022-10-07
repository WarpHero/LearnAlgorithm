//11653
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main() {
	int N;
	cin >> N;
	int tmp = N / 2;
	while (N>=2) {
		if (N % tmp == 0) {
			v.push_back(N / tmp);
			N = tmp;
			tmp = N / 2;
		}
		else {
			tmp--;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<<"\n";
	}

	return 0;
}