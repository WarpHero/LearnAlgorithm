//2292
#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    if (N == 1) printf("%d ", 1);
    else {
        int cnt = 1;
        int num = 7;
        while (1) {
            cnt++;
            if (N <= num) {
                break;
            }
            else {
                
                num += (6 * cnt);
            }
        }
        printf("%d ", cnt);
    }

    return 0;
}