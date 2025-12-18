#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M, u, v;
vector<int> cnt[1001]; //벡터 배열로 그래프 표현
bool visit[1001];
int result = 0;

// DFS 스택 이용
void dfs(int r) {
	stack<int> s;
	s.push(r); // while문 시작 전 루트 노드 삽입
	visit[r] = true;
	
	while(!s.empty()) {
		int cur = s.top();
		s.pop();
		for (auto c : cnt[cur]) {
			if (!visit[c]) {
				s.push(c);
				visit[c] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		// 무방향 그래프이기에 양쪽 다 추가
		cnt[u].push_back(v);
		cnt[v].push_back(u);
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			result++;
			dfs(i);
		}
	}
	
	cout << result;
	
	return 0;
}