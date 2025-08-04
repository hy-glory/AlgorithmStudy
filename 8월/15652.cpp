#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> v;

void dfs(int root){
	if (v.size() < M) {
		for (int n = root; n <= N; n++){
			v.push_back(n);
			dfs(n);
		}
		v.pop_back();
	} 
	else if (v.size() == M){
		for (auto vv : v) {
			cout << vv << ' ';
		}
		cout << '\n';
		v.pop_back();	
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++){
		v.push_back(i);
		dfs(i);
		v.clear();
	}

	return 0;
}
