#include <iostream>
#define ll long long

using namespace std;
int N, M;
int sum[1000001] = {0};
int count[1000001] = {0};
ll result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		sum[i] = (sum[i-1] + n) % M;
		count[sum[i]]++;
	}
	
	result += count[0];
	for (int i = 1; i < N; i++) {
		int s = sum[i];
		if (count[s] == 0) continue;
		else {
				count[s]--;
		result += count[s];
		}
	}
	
	cout << result;
	return 0;
}
