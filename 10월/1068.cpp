#include <iostream>
#include <vector>

using namespace std;

int N, n, x, root, child;
vector<int> t[50];
bool visit[50];
int result = 0;

void dfs(int c, int x) {
	if (c == x) return;
	int child = t[c].size();
	visit[c] = true;
	for (int next : t[c]) {
		if (!visit[next]) {
			if (next == x) child--;
			else dfs(next, x);
		}
	}
	if (child == 0) result++;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n == -1) root = i;
		else t[n].push_back(i);
	}
	
	cin >> x;

	dfs (root, x);
	cout << result;	
	
	return 0;
}