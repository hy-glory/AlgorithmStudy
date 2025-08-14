#include <iostream>
#include <vector>

using namespace std;
int N, M;
int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
bool used[9];
vector<int> result;

void dfs(int current) {
	if (current == M){
		for (auto v : result){
			cout << v << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++){
		if (!used[i]){
			used[i] = true;
			result.push_back(i);
			dfs(current+1);
			result.pop_back();
			used[i] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	dfs(0);
	
	return 0;
}
