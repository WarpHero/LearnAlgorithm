// Kruskal
// Node는 편의상 A부터 순서대로 0, 1, 2 로 치환해준다.
// UnionFind Algorithm 참고, 출처 : https://aeunhi99.tistory.com/65
// 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, pair<int, int>> p; //node1, node2, weight

int V = 10; // Vertex
vector<p> Edges; // Edge
vector<p> Result; //Result Tree
int StartND;
int Parent[10];
int TotalWeight =0;

int FindParent(int num){
    //부모 노드 찾기
    if(Parent[num]==num) return num;
    
    return Parent[num]=FindParent(Parent[num]);
}

void RootMerge(int num1, int num2){
    num1 = FindParent(num1);
    num2 = FindParent(num2);

    if(num1!=num2) Parent[num2]=num1;
}

void Init()
{

    // Root 자기자신으로 초기화하기
    for (int i = 0; i < V; i++)
    {
        Parent[i] = i;
    }

    // 제시된 그래프를 weight 기준으로 삽입 후 정렬한다.

    Edges.push_back({3, {0, 1}});
    Edges.push_back({4, {0, 2}});
    Edges.push_back({8, {1, 2}});
    Edges.push_back({2, {1, 3}});
    Edges.push_back({1, {1, 7}});
    Edges.push_back({7, {2, 3}});
    Edges.push_back({5, {2, 4}});
    Edges.push_back({6, {3, 4}});
    Edges.push_back({3, {3, 6}});
    Edges.push_back({2, {4, 5}});
    Edges.push_back({6, {5, 6}});
    Edges.push_back({6, {5, 9}});
    Edges.push_back({4, {6, 7}});
    Edges.push_back({8, {6, 9}});
    Edges.push_back({8, {7, 8}});
    Edges.push_back({9, {8, 9}});

    sort(Edges.begin(), Edges.end());

    StartND=Edges[0].second.first;

    printf("Start Node is %c\n", StartND+'A');

}

void KruskalGraph()
{
    for (int i = 0, len = Edges.size(); i < len; i++)
    {
        p cur = Edges[i];

        int nd = cur.second.first;
        int nd_ = cur.second.second;

        //Disjoint 확인
        if(FindParent(nd)==FindParent(nd_)) continue;

        Result.push_back(cur);
        TotalWeight += cur.first;
        
        if(StartND==nd_) printf("Node : %c , Weight : %d\n", nd+ 'A', cur.first);
        printf("Node : %c , Weight : %d\n", nd_+ 'A', cur.first);

        //Disjoint 갱신
        RootMerge(nd, nd_);

        //간선 다 찾으면 종료
        if(Result.size()==V-1) return;
    }
}

int main() {

    Init();
    KruskalGraph();
    printf("\nKruskal Graph total Weight is %d\n", TotalWeight);
    return 0;
}