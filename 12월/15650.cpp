#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visit[9];
vector<int> result;

void find(int c, int size) {
	if (size == M) {
		//cout << "size max: ";
		for (int r : result) cout << r << " ";
		cout << "\n";
		result.pop_back();
		return;
	}
	for (int i = c+1; i <= N; i++) {
		if (!visit[i]) {
			result.push_back(i);
			visit[i] = true;
			find(i, size+1);
			visit[i] = false;
		}
	}
	visit[c] = false;
	result.pop_back();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	if (N == 1) {
		cout << N;
		return 0;
	}
	
	int root = 1;
	while(root <= N-M+1) {
		result.push_back(root);
		visit[root] = true;
		//cout << "find root " << root << "\n";
		find(root, 1);
		result.clear();
		root++;
	}

	return 0;
}