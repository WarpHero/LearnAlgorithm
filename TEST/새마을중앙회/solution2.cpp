solution.cpp
2022-10-01 10:56:11

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> loans) {
    vector<int> answer;
    int len=loans.size();
    //int able[len]={0};
    for(int i=0;i<len;i++){
        int tmp=loans[i][2]; //대출가능 한도 계산

        tmp=tmp*(6-loans[i][0]); //직장등급 비례

        if(loans[i][1]<=3){
             tmp+=(1000/loans[i][1]);
        }
        else if(loans[i][1]==4){
            tmp+=100;
        }

        tmp-=loans[i][3]; //기존대출 제외하고 남은 금액

        if(tmp-loans[i][4]>=0){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }

    }
    return answer;
}