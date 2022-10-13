#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, R;
	cin >> N >> M >> R;

	int* arr = new int[N + 1];
	vector<vector<int>> v(N+1);
	stack <int> st;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i < N+1; i++) {
		arr[i] = 0;
		sort(v[i].begin, v[i].end());
	}
	
	arr[R] = 1;
	st.push(R);

	cout << st.top();


	return 0;
}