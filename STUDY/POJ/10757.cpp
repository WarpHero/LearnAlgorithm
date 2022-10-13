//10757
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int numA[10001], numB[10001];

int main() {
	string sA, sB;
	stack<int> st;
	cin >> sA >> sB;

	int len = max(sA.length(), sB.length());

	if (sA.length() < sB.length()) {
		string tmp = sA;
		sA = sB;
		sB = tmp;
	}

	for (int i = len; i > 0; i--) {
		numA[i] = sA[i - 1] - 48;
		
	}
	for (int i = sB.length(); i > 0; i--) {
		numB[i + (len - sB.length())] = sB[i - 1] - 48;
	}
	for (int i = len; i >= 0; i--) {
		int tmp = numA[i] + numB[i];
		if (tmp >= 10 && i > 0) {
			numA[i - 1]++;
			st.push(tmp % 10);
		}
		else {

			if (i == 0 && numA[0] == 0) break;
			st.push(tmp);
		}
	}

	while (!st.empty())
	{
		printf("%d", st.top());
		st.pop();
	}

	return 0;
}