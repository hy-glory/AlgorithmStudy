#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	int start, end;
	vector<pair<int, int>> v;
	
	for (int i = 0; i < N; i++){
		cin >> start >> end;
		v.push_back({end, start});
	}
	sort(v.begin(), v.end());
	
	int count = 1;
	int prev = v[0].first;
	for (int i = 1; i < N; i++){
		if (v[i].first == prev && v[i].second == prev) {
			count++;
			continue;
		}
		if (v[i].second >= prev){
			count++;
			prev = v[i].first;
			}
		
	}
	
	cout << count;
	return 0;
}
