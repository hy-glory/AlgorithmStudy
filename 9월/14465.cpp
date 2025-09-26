#include <iostream>
#include <algorithm>

using namespace std;
int N, K, B;
bool mat[100001];
int idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K >> B;
	
	for (int i = 0; i < B; i ++) {
		cin >> idx;
		mat[idx] = true;
	}
	
	int s = 1, e = K; // [s,e]
	int count = 0;
	for (int i = s; i <= e; i++) {
		if (mat[i]) count++;
	}
	int result = count;
	while (e < N) {
		if (mat[s]) count--;
		s++;
		e++;
		if(mat[e]) count++;
		result = min(result, count);
	}
	
	cout << result;
	
	return 0;
}
