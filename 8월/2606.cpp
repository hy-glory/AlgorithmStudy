#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool cnt[101][101] = {false};
bool visit[101] = {false};
queue<int> q;
int result;

void dfs(int cur) {
	int front = q.front();
	q.pop();
	for (int i = 1; i <= N; i++) {
		if (cnt[front][i] && !visit[i]) {
			visit[i] = true;
			q.push(i);
			result++;
			dfs(i);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cnt[s][e] = true;
		cnt[e][s] = true;
	}
	
	q.push(1);
	visit[1] = true;
	dfs(1);
	
	cout << result;
	return 0;
}
