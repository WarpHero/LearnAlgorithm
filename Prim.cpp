// Prim
// Start Node : A
// A부터 순서대로 0, 1, 2 로 치환해준다.
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> p;

int V = 10; // Vertex
vector<p> adj[10]; // Edge
bool visit[10];
char StartND = 'A';
int TotalWeight = 0;

void Init()
{
    // 제시된 그래프를 adj[Node_Number]에 <Node_Number, Weight> 형태로 저장해준다.

    // A=0
    adj[0].push_back({ 1, 3 });
    adj[0].push_back({ 2, 4 });
    // B=1
    adj[1].push_back({ 0, 3 });
    adj[1].push_back({ 2, 8 });
    adj[1].push_back({ 3, 2 });
    adj[1].push_back({ 7, 1 });
    // C
    adj[2].push_back({ 0, 4 });
    adj[2].push_back({ 1, 8 });
    adj[2].push_back({ 3, 7 });
    adj[2].push_back({ 4, 5 });
    // D
    adj[3].push_back({ 1, 2 });
    adj[3].push_back({ 2, 7 });
    adj[3].push_back({ 4, 6 });
    adj[3].push_back({ 6, 3 });
    // E
    adj[4].push_back({ 2, 5 });
    adj[4].push_back({ 3, 6 });
    adj[4].push_back({ 5, 2 });
    // F
    adj[5].push_back({ 4, 2 });
    adj[5].push_back({ 6, 6 });
    adj[5].push_back({ 9, 6 });
    // G
    adj[6].push_back({ 3, 3 });
    adj[6].push_back({ 5, 6 });
    adj[6].push_back({ 7, 4 });
    adj[6].push_back({ 9, 8 });
    // H
    adj[7].push_back({ 1, 1 });
    adj[7].push_back({ 6, 4 });
    adj[7].push_back({ 8, 8 });
    // I
    adj[8].push_back({ 7, 8 });
    adj[8].push_back({ 9, 9 });
    // J
    adj[9].push_back({ 5, 6 });
    adj[9].push_back({ 6, 8 });
    adj[9].push_back({ 8, 9 });
}

struct cmp
{
    bool operator()(p a, p b)
    {
        return a.second > b.second;
    }
};

void PrimGraph()
{
    // Vertex pair를 weight 기준으로 정렬
    priority_queue<p, vector<p>, cmp> pq;

    // priority queue 초기화
    while ((!pq.empty()))
    {
        pq.pop();
    }

    // Start Node와 연결된 node pq에 추가
    for (int i = 0, len = adj[0].size(); i < len; i++)
    {
        pq.push(adj[0][i]);
    }
    // Start Node는 방문했다고 가정
    visit[0] = true;

    int cnt = V-1;
    while (cnt > 0)
    {
        p curNode = pq.top();

        pq.pop();

        int nd = curNode.first;
        int w = curNode.second;

        // 이미 추가한 노드는 재방문 x
        if (visit[nd])
            continue;

        visit[nd] = true;
        cnt--;

        printf("Node : %c , Weight : %d\n", nd + StartND, w);
        TotalWeight += w;

        for (int i = 0, len = adj[nd].size(); i < len; i++)
        {
            int nextND = adj[nd][i].first;
            if (!visit[nextND])
            {
                // 방문하지 않은 연결 node를 pq에 넣는다.
                pq.push(adj[nd][i]);
            }
        }
    }
}

int main() {

    printf("Start Node is %c\n", StartND);
    Init();
    PrimGraph();

    printf("\n");
    printf("\nPrim Graph total Weight is %d\n", TotalWeight);

    return 0;
}