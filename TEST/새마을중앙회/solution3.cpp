solution.cpp
2022-10-01 11:33:22

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int fee, int comp, vector<int> shippings) {
    int answer =0; 
    int len=shippings.size();
    if(shippings[len-1]!=0) answer+=fee; //// 마지막 날은 무조건 임금 지불하므로
    /*int day=0;
    for(int i=0;i<len;i++){
        if(shippings[i]!=0) day++;
    }*/
    int compfee[16]={0};
    for(int i=0;i<len-1;i++){
        compfee[i]=shippings[i]*comp;
    }
    int cnt=1;    
    for(int i=len-2;i>=0;i--){

        if(shippings[i]==0) {
            cnt++;
        }
        else{
            int tmp;
            tmp=compfee[i]*cnt;

            if(tmp>fee){
                answer+=fee;
                cnt=1;
            }
            else{
                answer+=tmp;
                shippings[i]=0;
                cnt++;
            }
        }

    }
    return answer;
}