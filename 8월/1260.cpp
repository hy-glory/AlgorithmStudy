#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int N, M, V;
bool cnt[1001][1001] = {false,};
bool visit1[1001] = {false,};
bool visit2[1001] = {false,};
queue<int> q;
vector<int> result1;
vector<int> result2;

void dfs(int root) {
	for (int i = 1; i <= N; i++) {
		if (cnt[root][i] && !visit1[i]){
			visit1[i] = true;
			result1.push_back(i);
			dfs(i);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++){
	int s, e;
    	cin >> s >> e;
    	cnt[s][e] = true;
    	cnt[e][s] = true;
   }
   
	// dfs
	result1.push_back(V);
	visit1[V] = true;
	dfs(V);
	for (auto r : result1) {
		cout << r << ' ';
	}
	cout << '\n';
			
	// bfs
	q.push(V);
	visit2[V] = true;
	while(!q.empty()) {
		int front = q.front();
		result2.push_back(front);
		q.pop();
		for (int i = 1; i <= N; i++){
			if (cnt[front][i] && !visit2[i]){
				visit2[i] = true;
				q.push(i);
			}
		}
	}
	for (auto r : result2){
    	cout << r << ' ';
	}
	
	return 0;
}
