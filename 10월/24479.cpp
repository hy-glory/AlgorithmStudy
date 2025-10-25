#include <iostream>
#include <set>

using namespace std;

int N, M, R;
bool visited[100001]; 
set<int> E[100001];
int result[100001];
int count = 1;

void dfs(int V, set<int> E[], int R) {
	visited[R] = true;
	result[R] = count++; // 방문 순서 기록
	for (auto e : E[R]) {
		if(!visited[e]) {
			dfs(V, E, e);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> R;
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		E[u].insert(v);
		E[v].insert(u);
	}
	
	dfs(N, E, R);
	
	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}
	
	return 0;
}
