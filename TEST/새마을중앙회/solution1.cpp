solution.cpp
2022-10-01 10:32:23

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> judges, vector<vector<int>> musics) {
    vector<int> answer;
    int len=judges.size();
    int arr[100]={0,};
    for(int i=0;i<len;i++){ //i=참가자
        sort(judges[i].begin(), judges[i].end());
        sort(musics[i].begin(), musics[i].end());
        int score=0; //심사위원 점수
        for(int j=1;j<4;j++){
            score+=judges[i][j];
        }
        int diff=0;
        diff=(musics[i][3]+musics[i][2]-musics[i][0]-musics[i][1]); //난이도

        arr[i]=(score*diff);      

    }
    int maxscore=arr[0];
    int idx=0;
    for(int i=1;i<len;i++){
        if(maxscore<arr[i]){
            idx=i;
            maxscore=arr[i];
        }
    }
    answer.push_back(idx+1);
    answer.push_back(maxscore);
    return answer;
}