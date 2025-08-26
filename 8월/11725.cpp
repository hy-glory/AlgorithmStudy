#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
vector<int> n[100001];
bool visit[100001] = {false,};
queue<int> q;
set<pair<int,int>> result;
int N;

void dfs(int cur) {
	if (q.empty()) return;
	int front = q.front();
	q.pop();
	for (auto k : n[front]) {
		if (!visit[k]) {
			visit[k] = true;
			q.push(k);
			result.insert({k, front});
			dfs(k);
		}
	}
	return;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	int s, e;
	for (int i = 1; i < N; i++) {
		cin >> s >> e;
		n[s].push_back(e);
		n[e].push_back(s);		
	}

	q.push(1);
	visit[1] = true;
	dfs(1);
 
	
	for (auto ss : result) {
		cout << ss.second << '\n';
	}
	
	return 0;
}