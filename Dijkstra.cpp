#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#define MAX_VAL -100
using namespace std;
int n, m, s;
class Vertex {
public:
	int value;
	int dist;
	int post = 0;
	Vertex(int value, int dist, int post) :
		value(value), dist(dist), post(post) {
	}

	Vertex(int value) :value(value) {
		dist = MAX_VAL;
	}
	void setDist(int d) {
		dist = d;
	}
	bool operator>(const Vertex& v)const {
		return dist > v.dist;
	}
	bool operator<(const Vertex& v)const {
		return dist < v.dist;
	}
};
class Graph {
public:
	int n = 0;
	vector<Vertex> vt;
	vector<vector<pair<int, int>>>adj;
	priority_queue<Vertex> pq;
	map<int, pair<int, int>>m;
	void addVertex(int value, int dist) {
		vt.push_back(Vertex(value, dist, value));
		n = vt.size();
		adj.resize(n + 1);
	}
	void addVertex(int value) {
		vt.push_back(Vertex(value));
		n = vt.size();
		adj.resize(n);
	}
	void addAdj(int u, int v, int w) {
		adj[u - 1].push_back(make_pair(v, w));
	}
	void setStart(int value) {
		vt[value - 1].setDist(0);
		vt[value - 1].post = value;
	}
	void Dijkstra_R(int s) {
		vector<int>dist(n, -1 * MAX_VAL);
		dist[s - 1] = 0;
		setStart(s);
		for (int i = 0; i < n; i++) {
			pq.push(vt[i]);
		}
		m.insert(make_pair(s, make_pair(0, -1)));
		while (!pq.empty()) {
			int value = pq.top().value - 1;
			int cost = -1 * pq.top().dist;
			pq.pop();
			if (dist[value] < cost) continue;
			for (int i = 0; i < adj[value].size(); i++) {
				int n = adj[value][i].first;
				int v = adj[value][i].second;
				if (dist[n - 1] > dist[value] + v) {
					dist[n - 1] = dist[value] + v;
					Vertex newVt = Vertex(n, -dist[n - 1], value + 1);
					pq.push(newVt);
					m[n] = make_pair(dist[n - 1], value + 1);
				}
			}
		}
		printf("\n\n 누적 가중치 - MIN_ROUTE - 이전Vertex \n");
		for (int i = 1; i <= m.size(); i++) {
			printf("%d - %d - %d \n", i, m[i].first, m[i].second);

		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%d 까지 경로 : ", i);
			if (dist[i - 1] != -MAX_VAL) {
				stack<int> st;
				int next_R = m[i].second;
				while (next_R != -1) {
					st.push(next_R);
					next_R = m[next_R].second;
				}
				while (!st.empty()) {
					printf("%d - ", st.top());
					st.pop();
				}
				printf("%d\n", i);
			}
		}
	}
};
int main() {
	printf("꼭지점의 수를 입력하시오 : ");
    cin>>n;
    
	//scanf_s("%d", &n);
	printf("그래프의 전체 차수를 입력하시오 : ");
	cin>>m;
    //scanf_s("%d", &m);
	printf("출발 노드를 입력하시오(숫자) : ");
	cin>>s;
    //scanf_s("%d", &s);
	Graph gp;
	for (int i = 0; i < n; i++) {
		gp.addVertex(i + 1);
	}
	for (int i = 0; i < m; i++) {
		printf("시작 노드 / 도착 노드 / 가중치를 차례로 입력하시오.\n");
		int u, v, w;
        cin>>u>>v>>w;
		//scanf_s("%d %d %d", &u, &v, &w);
		gp.addAdj(u, v, w);
	}
	gp.Dijkstra_R(s);
}