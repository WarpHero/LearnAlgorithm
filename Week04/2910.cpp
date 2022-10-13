#include <vector>
#include <map>
using namespace std;

map<int, int> num, numser;
map<int, bool> chk;//pair차이점 : Key값 중복x
vector <int> series;

int main() {
	int cnt = 0;
	int N, C, tmp;
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		num[tmp]++;
		if (!chk[tmp]) {
			numser[tmp] = (++cnt);
			series.push_back(tmp);
			chk[tmp] = true;
		}
	}

	for (int i = 0; i < series.size(); i++) {

	}


	return 0;
}