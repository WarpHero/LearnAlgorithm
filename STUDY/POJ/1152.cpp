#include <iostream>
#include <vector>
#define LEN 1000000 
using namespace std;

char chr[LEN];

int main(){

    int cnt=0;

    gets(chr);

    if(chr[0]!=' '&& chr[1]!=' '){

        for(int i=1; i<LEN ;i++){

            if(chr[i-1]=' ' && chr[i]==' ') break;

            if(chr[i]==' ') cnt++;
        }
    }
    printf("%d", cnt);
}
