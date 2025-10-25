#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M, u, v;
vector<int> cnt[1001];
bool visit[1001];
int result = 0;

void dfs(int r) {
	stack<int> s;
	s.push(r);
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